#include "Processor.h"
#include "Editor.h"

const juce::Identifier xmlName{"clean-machine"};

Processor::Processor()
: AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true).withOutput("Output", juce::AudioChannelSet::stereo(), true)),
parameterState(*this, nullptr, xmlName, {
    std::make_unique<juce::AudioParameterFloat>("drive", "Drive", juce::NormalisableRange<float>(-60.0f, 60.0f, 0.1f), 0.0f),
    std::make_unique<juce::AudioParameterInt>("highPass", "High pass", 0, 600, 0),
    std::make_unique<juce::AudioParameterFloat>("attack", "Attack", juce::NormalisableRange<float>(0.1f, 300.0f, 0.1f, 0.5f), 10.0f),
    std::make_unique<juce::AudioParameterFloat>("release", "Release", juce::NormalisableRange<float>(0.1f, 300.0f, 0.1f, 0.5f), 100.0f),
    std::make_unique<juce::AudioParameterFloat>("transition", "Transition", juce::NormalisableRange<float>(0.1f, 300.0f, 0.1f, 0.5f), 20.0f),
    std::make_unique<juce::AudioParameterInt>("mix", "Mix", 0, 100, 100),
    std::make_unique<juce::AudioParameterFloat>("makeup", "Make up", juce::NormalisableRange<float>(-12.0f, 12.0f, 0.1f), 0.0f),
}),
parameters(parameterState),
compressor(parameters) {}

bool Processor::isBusesLayoutSupported(const BusesLayout& layouts) const {
    auto inputs = layouts.getMainInputChannelSet();
    auto outputs = layouts.getMainOutputChannelSet();
    auto mono = juce::AudioChannelSet::mono();
    auto stereo = juce::AudioChannelSet::stereo();
    return (inputs == mono && outputs == mono) || (inputs == stereo && outputs == stereo);
}

void Processor::prepareToPlay(double sampleRate, int /* maximumExpectedSamplesPerBlock */) {
    parameters.setSampleRate(sampleRate);
    compressor.reset();
    reportedGainReduction.store(1.0);
}

void Processor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    juce::ScopedNoDenormals noDenormals;

    parameters.update();

    int inputChannels = getTotalNumInputChannels();
    int outputChannels = getTotalNumOutputChannels();
    int samplesN = buffer.getNumSamples();

    double gainReduction = 1.0;
    
    if (inputChannels == 2 && outputChannels == 2) {
        for (int sample = 0; sample < samplesN; sample++) {
            double left = buffer.getSample(0, sample);
            double right = buffer.getSample(1, sample);

            double avg = (left + right) * 0.5;
            double relative = compressor.computeRelativeOutput(avg, gainReduction);

            buffer.setSample(0, sample, static_cast<float>(left * relative));
            buffer.setSample(1, sample, static_cast<float>(right * relative));
        }
    } else if (inputChannels == 1 && outputChannels == 1) {
        for (int sample = 0; sample < samplesN; sample++) {
            double input = buffer.getSample(0, sample);
            double relative = compressor.computeRelativeOutput(input, gainReduction);
            buffer.setSample(0, sample, static_cast<float>(input * relative));
        }
    } else {
        buffer.clear();
    }

    double prevGainReduction = reportedGainReduction.load();
    while (gainReduction < prevGainReduction && !reportedGainReduction.compare_exchange_weak(prevGainReduction, gainReduction)) {}
}

void Processor::getStateInformation(juce::MemoryBlock& destData) {
    std::unique_ptr<juce::XmlElement> xml = parameterState.copyState().createXml();
    copyXmlToBinary(*xml, destData);
}

void Processor::setStateInformation(const void* data, int size) {
    std::unique_ptr<juce::XmlElement> xml = getXmlFromBinary(data, size);
    if (xml.get() == nullptr) return;
    if (!xml->hasTagName(xmlName)) return;
    parameterState.replaceState(juce::ValueTree::fromXml(*xml));
}

juce::AudioProcessorEditor* Processor::createEditor() {
    return new Editor(*this, parameterState, reportedGainReduction);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Processor();
}
