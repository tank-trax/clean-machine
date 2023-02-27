#pragma once

#include <JuceHeader.h>
#include "LookAndFeel.h"
#include "Heart.h"
#include "Meter.h"

class Editor : public juce::AudioProcessorEditor {
public:
    Editor(juce::AudioProcessor&, juce::AudioProcessorValueTreeState& parameters, std::atomic<double>& gainReduction);

    void paint(juce::Graphics& graphics) override;
private:
    void initSlider(const juce::String& labelText, juce::Slider& slider, juce::Label& label, int y);

    LookAndFeel look;
    Meter meter;
    Heart heart;

    juce::Slider driveSlider;
    juce::Label driveLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment driveAttach;

    juce::Slider highPassSlider;
    juce::Label highPassLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment highPassAttach;

    juce::Slider attackSlider;
    juce::Label attackLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment attackAttach;

    juce::Slider releaseSlider;
    juce::Label releaseLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment releaseAttach;

    juce::Slider transitionSlider;
    juce::Label transitionLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment transitionAttach;

    juce::Slider mixSlider;
    juce::Label mixLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment mixAttach;

    juce::Slider makeupSlider;
    juce::Label makeupLabel;
    juce::AudioProcessorValueTreeState::SliderAttachment makeupAttach;
};
