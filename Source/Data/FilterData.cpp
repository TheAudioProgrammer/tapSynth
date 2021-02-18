/*
  ==============================================================================

    FilterData.cpp
    Created: 18 Feb 2021 9:26:23pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include "FilterData.h"

void FilterData::setParams (const int filterType, const float filterCutoff, const float filterResonance)
{
    selectFilterType (filterType);
    setCutoffFrequency (filterCutoff);
    setResonance (filterResonance);
}

void FilterData::selectFilterType (const int filterType)
{
    switch (filterType)
    {
        case 0:
            setType (juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
            
        case 1:
            setType (juce::dsp::StateVariableTPTFilterType::bandpass);
            break;
            
        case 2:
            setType (juce::dsp::StateVariableTPTFilterType::highpass);
            break;
            
        default:
            setType (juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
    }
}
