/*
  ==============================================================================

    AdsrComponent.h
    Created: 7 Feb 2021 2:28:49pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomComponent.h"

//==============================================================================
/*
*/
class AdsrComponent : public CustomComponent
{
public:
    AdsrComponent (juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId);
    ~AdsrComponent() override;

    void resized() override;

private:
    SliderWithLabel attack;
    SliderWithLabel decay;
    SliderWithLabel sustain;
    SliderWithLabel release;
    
    static constexpr int sliderWidth = 50;
    static constexpr int sliderHeight = 260;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
