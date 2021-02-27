/*
  ==============================================================================

    MeterData.h
    Created: 27 Feb 2021 9:37:46pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class MeterData
{
public:
    void processRMS (juce::AudioBuffer<float>& buffer);
    void processPeak (juce::AudioBuffer<float>& buffer);
    
    const std::atomic<float>& getRMS() { return rms; }
    const std::atomic<float>& getPeak() { return peak; }
    
private:
    std::atomic<float> rms { 0.0f };
    std::atomic<float> peak { 0.0f };
};
