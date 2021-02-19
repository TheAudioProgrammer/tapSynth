/*
  ==============================================================================

    FilterComponent.cpp
    Created: 18 Feb 2021 10:00:39pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent (juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeId, juce::String cutoffId, juce::String resonanceId)
{
    juce::StringArray filterTypeChoices { "Low Pass", "Band Pass", "High Pass" };
    filterTypeSelector.addItemList (filterTypeChoices, 1);
    filterTypeSelector.setSelectedItemIndex (0);
    addAndMakeVisible (filterTypeSelector);
    
    filterTypeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, filterTypeId, filterTypeSelector);
    
    setSliderParams (cutoffSlider, cutoffLabel, cutoffAttachment, cutoffId, apvts);
    setSliderParams (resonanceSlider, resonanceLabel, resonanceAttachment, resonanceId, apvts);
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    auto bounds = getLocalBounds();
    g.setColour (juce::Colours::white);
    g.drawRoundedRectangle (bounds.toFloat().reduced (10.0f), 5.0f, 2.0f);
    
    g.setColour (juce::Colours::yellow);
    g.setFont (fontHeight);
    g.setFont (g.getCurrentFont().boldened());
    g.drawText (name, 20, 15, 100, 25, juce::Justification::left);
}

void FilterComponent::resized()
{
    const auto dialSize = 70;
    const auto labelWidth = 70;
    const auto labelHeight = 18;
    const auto startX = 18;
    const auto startY = 40;
    
    filterTypeSelector.setBounds (startX, startY, 145, 25);
    cutoffLabel.setBounds (startX, 80, labelWidth, labelHeight);
    cutoffSlider.setBounds (startX, 95, dialSize, dialSize);
    resonanceLabel.setBounds (cutoffLabel.getRight(), 80, labelWidth, labelHeight);
    resonanceSlider.setBounds (cutoffSlider.getRight(), 95, dialSize, dialSize);
}

using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void FilterComponent::setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    addAndMakeVisible (slider);
    
    label.setFont (fontHeight);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
    
    attachment = std::make_unique<SliderAttachment>(apvts, paramId, slider);
}
