/*
  ==============================================================================

    MeterData.cpp
    Created: 27 Feb 2021 9:37:46pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include "MeterData.h"

void MeterData::processRMS (juce::AudioBuffer<float>& buffer)
{
    // Running total of all samples in the callback
    float sum = 0;

    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto output = buffer.getReadPointer (ch);

        for (int s = 0; s < buffer.getNumSamples(); ++s)
        {
            auto squaredSample = output[s] * output[s];
            sum+=squaredSample;
        }

        auto avg = sum / buffer.getNumSamples();
        rms.store (std::sqrt (avg));
    }
}

void MeterData::processPeak (juce::AudioBuffer<float>& buffer)
{
    auto max = 0.0f;

    for (int ch = 0; ch < buffer.getNumChannels(); ++ch)
    {
        auto output = buffer.getReadPointer (ch);
        
        for (int s = 0; s < buffer.getNumSamples(); ++s)
        {
            auto abs = std::abs (output[s]);
            
            if (abs > max)
                max = abs;
        }
        
        peak.store (max);
    }
}




