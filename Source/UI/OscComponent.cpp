/*
  ==============================================================================

    OscComponent.cpp
    Created: 14 Feb 2021 6:51:39pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String oscId, juce::String gainId, juce::String pitchId, juce::String fmFreqId, juce::String fmDepthId)
: gain ("Gain", gainId, apvts, dialWidth, dialHeight)
, pitch ("Pitch", pitchId, apvts, dialWidth, dialHeight)
, fmFreq ("FM Freq", fmFreqId, apvts, dialWidth, dialHeight)
, fmDepth ("FM Depth", fmDepthId, apvts, dialWidth, dialHeight)
{
    juce::StringArray oscChoices { "Sine", "Saw", "Square" };
    oscSelector.addItemList (oscChoices, 1);
    oscSelector.setSelectedItemIndex (0);
    addAndMakeVisible (oscSelector);
    
    oscSelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, oscId, oscSelector);
    
    addAndMakeVisible (gain);
    addAndMakeVisible (pitch);
    addAndMakeVisible (fmFreq);
    addAndMakeVisible (fmDepth);
}

OscComponent::~OscComponent()
{
}


void OscComponent::resized()
{
    const auto yStart = 15;
    const auto width = 70;
    const auto height = 88;
    
    oscSelector.setBounds (18, 40, 100, 25);
    gain.setBounds (120, yStart, width, height);
    pitch.setBounds (190, yStart, width, height);
    fmFreq.setBounds (260, yStart, width, height);
    fmDepth.setBounds (330, yStart, width, height);
}
