#pragma once

#include <JuceHeader.h>

class Parameters {
public:
    Parameters(const juce::AudioProcessorValueTreeState& state);

    void setSampleRate(double sampleRate);
    void update();

    double gainK = 0.0;
    double driveTarget = 0.0;
    double highPassK = 0.0;
    double logAttack = 0.0;
    double logRelease = 0.0;
    double transition = 0.0;
    double mixTarget = 0.0;
    double makeupTarget = 0.0;
private:
    double getSpeedK(double ms) const;

    double sampleRate = 0.0;

    std::atomic<float>& driveState;
    std::atomic<float>& highPassState;
    std::atomic<float>& attackState;
    std::atomic<float>& releaseState;
    std::atomic<float>& transitionState;
    std::atomic<float>& mixState;
    std::atomic<float>& makeupState;
};
