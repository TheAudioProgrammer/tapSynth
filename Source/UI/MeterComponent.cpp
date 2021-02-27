/*
  ==============================================================================

    MeterComponent.cpp
    Created: 27 Feb 2021 2:11:36am
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MeterComponent.h"

//==============================================================================
MeterComponent::MeterComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

MeterComponent::~MeterComponent()
{
}

void MeterComponent::paintOverChildren (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced (20, 35).translated (0, 10);
    auto leftMeter = bounds.removeFromTop (bounds.getHeight() / 2).reduced (0, 5);
    auto rightMeter = bounds.reduced (0, 5);
    g.setColour (juce::Colours::white);
    g.drawRoundedRectangle (leftMeter.toFloat(), 5, 2.0f);
    g.drawRoundedRectangle (rightMeter.toFloat(), 5, 2.0f);
}

void MeterComponent::resized()
{
   
}
