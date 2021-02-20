/*
  ==============================================================================

    FilterComponent.h
    Created: 18 Feb 2021 10:00:39pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomComponent.h"

//==============================================================================
/*
*/
class FilterComponent : public CustomComponent
{
public:
    FilterComponent (juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeId, juce::String cutoffId, juce::String resonanceId);
    ~FilterComponent() override;

    void resized() override;

private:
    juce::ComboBox filterTypeSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeAttachment;
    
    SliderWithLabel cutoff;
    SliderWithLabel resonance;
    
    static constexpr int dialWidth = 70;
    static constexpr int dialHeight = 70;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
