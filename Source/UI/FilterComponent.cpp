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
: cutoff ("Cutoff", cutoffId, apvts, dialWidth, dialHeight)
, resonance ("Resonance", resonanceId, apvts, dialWidth, dialHeight)
{
    juce::StringArray filterTypeChoices { "Low Pass", "Band Pass", "High Pass" };
    filterTypeSelector.addItemList (filterTypeChoices, 1);
    filterTypeSelector.setSelectedItemIndex (0);
    addAndMakeVisible (filterTypeSelector);
    
    filterTypeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, filterTypeId, filterTypeSelector);
    
    addAndMakeVisible (cutoff);
    addAndMakeVisible (resonance);
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::resized()
{
    const auto startX = 18;
    const auto startY = 80;
    const auto width = 70;
    const auto height = 88;
    
    filterTypeSelector.setBounds (18, 40, 145, 25);
    cutoff.setBounds (startX, startY, width, height);
    resonance.setBounds (cutoff.getRight(), startY, width, height);
}


