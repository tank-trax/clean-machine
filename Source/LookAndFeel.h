#pragma once

#include <JuceHeader.h>

class LookAndFeel : public juce::LookAndFeel_V4 {
public:
    juce::Label* createSliderTextBox(juce::Slider& slider) override;
};
