#include "Editor.h"
#include "Fonts.h"
#include "LookAndFeel.h"

const juce::Font sansFont = Fonts::getSans();

Editor::Editor(juce::AudioProcessor& processor, juce::AudioProcessorValueTreeState& parameterState, std::atomic<double>& gainReduction)
: AudioProcessorEditor(&processor),
meter(gainReduction),
driveAttach(parameterState, "drive", driveSlider),
highPassAttach(parameterState, "highPass", highPassSlider),
attackAttach(parameterState, "attack", attackSlider),
releaseAttach(parameterState, "release", releaseSlider),
transitionAttach(parameterState, "transition", transitionSlider),
mixAttach(parameterState, "mix", mixSlider),
makeupAttach(parameterState, "makeup", makeupSlider) {
    setLookAndFeel(&look);
    setSize(528, 300);

    auto track = juce::Colour(0xff1a234d);
    look.setColour(juce::Slider::thumbColourId, juce::Colour(0xff9569c2));
    look.setColour(juce::Slider::trackColourId, track);
    look.setColour(juce::Slider::backgroundColourId, track);

    initSlider("Drive", driveSlider, driveLabel, 19);
    initSlider("High pass", highPassSlider, highPassLabel, 49);
    initSlider("Attack", attackSlider, attackLabel, 99);
    initSlider("Release", releaseSlider, releaseLabel, 129);
    initSlider("Transition", transitionSlider, transitionLabel, 159);
    initSlider("Mix", mixSlider, mixLabel, 209);
    initSlider("Make up", makeupSlider, makeupLabel, 239);

    meter.setBounds(20, 20, 35, 260);
    addAndMakeVisible(meter);

    heart.setBounds(504, 276, 24, 24);
    addAndMakeVisible(heart);
}

void Editor::initSlider(const juce::String& labelText, juce::Slider& slider, juce::Label& label, int y) {
    slider.setLookAndFeel(&look);
    slider.setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 20);
    slider.setBounds(130, y, 370, 30);
    label.setText(labelText, juce::dontSendNotification);
    label.setFont(sansFont);
    label.setColour(juce::Label::textColourId, juce::Colours::white);
    label.attachToComponent(&slider, true);

    addAndMakeVisible(slider);
    addAndMakeVisible(label);
}

void Editor::paint(juce::Graphics& graphics) {
    graphics.fillAll(juce::Colour(0xff070b1f));
}
