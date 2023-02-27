#include "Parameters.h"

const double twoPi = juce::MathConstants<double>::twoPi;

Parameters::Parameters(const juce::AudioProcessorValueTreeState& state) :
driveState(*state.getRawParameterValue("drive")),
highPassState(*state.getRawParameterValue("highPass")),
attackState(*state.getRawParameterValue("attack")),
releaseState(*state.getRawParameterValue("release")),
transitionState(*state.getRawParameterValue("transition")),
mixState(*state.getRawParameterValue("mix")),
makeupState(*state.getRawParameterValue("makeup")) {}

void Parameters::setSampleRate(double sampleRate_) {
    sampleRate = sampleRate_;
    gainK = getSpeedK(30.0);
    update();
}

double Parameters::getSpeedK(double ms) const {
    return 1.0 - std::exp(-1.0 / (sampleRate * ms * 0.001));
}

void Parameters::update() {
    highPassK = 1.0 - std::exp(-twoPi * highPassState.load() / sampleRate);
    driveTarget = juce::Decibels::decibelsToGain(driveState.load() + 12.0);
    logAttack = std::log2(getSpeedK(attackState.load()));
    logRelease = std::log2(getSpeedK(releaseState.load()));
    transition = getSpeedK(transitionState.load());
    mixTarget = mixState.load() * 0.01;
    makeupTarget = juce::Decibels::decibelsToGain(makeupState.load());
}
