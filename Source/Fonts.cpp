#include "Fonts.h"

juce::Font Fonts::getSans() {
    auto typeface = juce::Typeface::createSystemTypefaceFor(BinaryData::Karla_ttf, BinaryData::Karla_ttfSize);
    return juce::Font(typeface).withHeight(16);
}

juce::Font Fonts::getMono() {
    auto typeface = juce::Typeface::createSystemTypefaceFor(BinaryData::IBMPlexMono_ttf, BinaryData::IBMPlexMono_ttfSize);
    return juce::Font(typeface).withHeight(16);
}
