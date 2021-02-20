/*
  ==============================================================================

    ReverbComponent.cpp
    Created: 19 Feb 2021 9:18:11pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ReverbComponent.h"

//==============================================================================
ReverbComponent::ReverbComponent (juce::AudioProcessorValueTreeState& apvts, juce::String sizeId, juce::String dampingId, juce::String widthId, juce::String dryId, juce::String wetId, juce::String freezeId)
: size ("Size", sizeId, apvts, dialWidth, dialHeight)
, damping ("Damping", dampingId, apvts, dialWidth, dialHeight)
, stereoWidth ("Width", widthId, apvts, dialWidth, dialHeight)
, dry ("Dry", dryId, apvts, dialWidth, dialHeight)
, wet ("Wet", wetId, apvts, dialWidth, dialHeight)
, freeze ("Freeze", freezeId, apvts, dialWidth, dialHeight)
{
    addAndMakeVisible (size);
    addAndMakeVisible (damping);
    addAndMakeVisible (stereoWidth);
    addAndMakeVisible (dry);
    addAndMakeVisible (wet);
    addAndMakeVisible (freeze);
    
    setName ("Reverb");
}

ReverbComponent::~ReverbComponent()
{
}

void ReverbComponent::resized()
{
    const auto yStart = 40;
    const auto width = 67;
    const auto height = 88;
    
    size.setBounds (10, yStart, width, height);
    damping.setBounds (size.getRight(), yStart, width, height);
    stereoWidth.setBounds (damping.getRight(), yStart, width, height);
    dry.setBounds (stereoWidth.getRight(), yStart, width, height);
    wet.setBounds (dry.getRight(), yStart, width, height);
    freeze.setBounds (wet.getRight(), yStart, width, height);
}

