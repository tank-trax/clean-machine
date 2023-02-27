#pragma once

#include <JuceHeader.h>

class Meter : public juce::Component, juce::Timer {
public:
    Meter(std::atomic<double>& gainReduction);

    void paint(juce::Graphics& graphics) override;
    void timerCallback() override;
private:
    std::atomic<double>& gainReduction;
    double dbEnv = 0.0;
};
