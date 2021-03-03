/*
  ==============================================================================

    ReverbComponent.h
    Created: 19 Feb 2021 9:18:11pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomComponent.h"

//==============================================================================
/*
*/
class ReverbComponent  : public CustomComponent
{
public:
    ReverbComponent (juce::AudioProcessorValueTreeState& apvts, juce::String sizeId, juce::String dampingId, juce::String widthId, juce::String dryId, juce::String wetId, juce::String freezeId);
    ~ReverbComponent() override;

    void resized() override;

private:
    SliderWithLabel size;
    SliderWithLabel damping;
    SliderWithLabel stereoWidth;
    SliderWithLabel dry;
    SliderWithLabel wet;
    SliderWithLabel freeze;
    
    static constexpr int dialWidth = 64;
    static constexpr int dialHeight = 90;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbComponent)
};
