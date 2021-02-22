/*
  ==============================================================================

    FilterData.h
    Created: 18 Feb 2021 9:26:23pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include "OscData.h"
#include <JuceHeader.h>


class FilterData : public juce::dsp::StateVariableTPTFilter<float>
{
public:
    FilterData();
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void setParams (const int filterType, const float filterCutoff, const float filterResonance);
    void setLfoParams (const float freq, const float depth);
    void processNextBlock (juce::AudioBuffer<float>& buffer);
    float processNextSample (int channel, float inputValue);
    void resetAll();
    
private:
    void selectFilterType (const int type);
    juce::dsp::Oscillator<float> lfo { [](float x) { return std::sin (x); }};
};
