#include "Fonts.h"
#include "LookAndFeel.h"

const juce::Font monoFont = Fonts::getMono();

juce::Label* LookAndFeel::createSliderTextBox(juce::Slider& slider) {
    auto label = new juce::Label();

    label->setJustificationType(juce::Justification::left);
    label->setKeyboardType(juce::TextInputTarget::decimalKeyboard);
    label->setFont(monoFont);

    label->setColour(juce::Label::textColourId, juce::Colours::white);
    label->setColour(juce::Label::backgroundColourId, juce::Colours::transparentBlack);
    label->setColour(juce::Label::outlineColourId, juce::Colours::transparentBlack);
    label->setColour(juce::TextEditor::textColourId, juce::Colours::white);
    label->setColour(juce::TextEditor::backgroundColourId, juce::Colours::transparentBlack);
    label->setColour(juce::TextEditor::focusedOutlineColourId, juce::Colours::transparentBlack);
    label->setColour(juce::TextEditor::highlightColourId, juce::Colours::rebeccapurple);
    label->setColour(juce::CaretComponent::caretColourId, juce::Colours::white);

    return label;
}
