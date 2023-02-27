#pragma once

#include <JuceHeader.h>
#include "Compressor.h"
#include "Parameters.h"

class Processor : public juce::AudioProcessor {
public:
    Processor();

    const juce::String getName() const override { return JucePlugin_Name; }
    bool hasEditor() const override { return true; }

    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }
    int getNumPrograms() override { return 0; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}
    void releaseResources() override {}

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void prepareToPlay(double sampleRate, int /* maximumExpectedSamplesPerBlock */) override;
    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) override;
    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;
    juce::AudioProcessorEditor* createEditor() override;
private:
    juce::AudioProcessorValueTreeState parameterState;
    Parameters parameters;
    Compressor compressor;
    std::atomic<double> reportedGainReduction{1.0};
};
