#include "Heart.h"

using namespace std::literals::chrono_literals;

const juce::URL url{"https://amalgamatedsignals.com/buy/clean-machine"};

Heart::Heart() {
    addMouseListener(this, false);
}

void Heart::paint(juce::Graphics& graphics) {
    graphics.fillAll(juce::Colour(0xff070b1f));
    auto heartColor = highlighted ? juce::Colour(0xffa82f8e) : juce::Colour(0xff273370);

    icon->replaceColour(juce::Colours::white, heartColor);
    icon->drawAt(graphics, 4.0f, 4.0f, 1.0f);
    icon->replaceColour(heartColor, juce::Colours::white);
}

void Heart::mouseEnter(const juce::MouseEvent&) {
    setMouseCursor(juce::MouseCursor::PointingHandCursor);
    highlighted = true;
    repaint();
}

void Heart::mouseExit(const juce::MouseEvent&) {
    highlighted = false;
    repaint();
}

void Heart::mouseDown(const juce::MouseEvent&) {
    auto now = std::chrono::steady_clock::now();
    if ((now - lastClicked) / 1ms < 100) return;

    lastClicked = now;
    url.launchInDefaultBrowser();
}
