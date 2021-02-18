/*
  ==============================================================================

    FilterData.h
    Created: 18 Feb 2021 9:26:23pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


class FilterData : public juce::dsp::StateVariableTPTFilter<float>
{
public:
    void setParams (const int filterType, const float filterCutoff, const float filterResonance);
private:
    void selectFilterType (const int type);
};
