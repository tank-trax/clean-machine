#pragma once

#include <JuceHeader.h>

class Heart : public juce::Component {
public:
    Heart();

    void paint(juce::Graphics& graphics) override;
    void mouseEnter(const juce::MouseEvent&) override;
    void mouseExit(const juce::MouseEvent&) override;
    void mouseDown(const juce::MouseEvent&) override;
private:
    std::unique_ptr<juce::Drawable> icon{juce::Drawable::createFromImageData(BinaryData::heart_svg, BinaryData::heart_svgSize)};
    bool highlighted = false;
    std::chrono::time_point<std::chrono::steady_clock> lastClicked;
};
