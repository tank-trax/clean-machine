#include "Meter.h"

const double attack = 1.0 - std::exp(-1.0 / (24.0 * 0.006));
const double release = 1.0 - std::exp(-1.0 / (24.0 * 0.06));

Meter::Meter(std::atomic<double>& gainReduction)
: gainReduction(gainReduction) {
    startTimerHz(24);
}

void Meter::paint(juce::Graphics& graphics) {
    graphics.fillAll(juce::Colour(0xff070b1f));

    auto base = juce::Colours::rebeccapurple;
    float hue = base.getHue();
    float sat = base.getSaturation();
    float bright = 0.7f;

    float remaining = static_cast<float>(dbEnv);
    int pos = 0;
    while (true) {
        bright += 0.01f;
        sat -= 0.01f;
        if (remaining < 1.0f) {
            graphics.setColour(juce::Colour::fromHSV(hue, sat, bright, remaining));
            graphics.fillRect(0, pos, 10, 10);
            break;
        } else {
            graphics.setColour(juce::Colour::fromHSV(hue, sat, bright, 1.0f));
            graphics.fillRect(0, pos, 10, 10);
            pos += 13;
            remaining -= 1.0f;
        }
    }
}

void Meter::timerCallback() {
    double db = -juce::Decibels::gainToDecibels(gainReduction.exchange(1.0));
    if (db > 20.0) db = 20.0;

    double speed = db > dbEnv ? attack : release;
    dbEnv += speed * (db - dbEnv);
    repaint();
}
