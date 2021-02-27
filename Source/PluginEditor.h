/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/OscComponent.h"
#include "UI/FilterComponent.h"
#include "UI/AdsrComponent.h"
#include "UI/LfoComponent.h"
#include "UI/ReverbComponent.h"
#include "UI/MeterComponent.h"
#include "UI/Assets.h"

//==============================================================================
/**
*/
class TapSynthAudioProcessorEditor  : public juce::AudioProcessorEditor
, public juce::Timer
{
public:
    TapSynthAudioProcessorEditor (TapSynthAudioProcessor&);
    ~TapSynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override;

private:
    TapSynthAudioProcessor& audioProcessor;
    OscComponent osc1;
    OscComponent osc2;
    FilterComponent filter;
    AdsrComponent adsr;
    LfoComponent lfo1;
    AdsrComponent filterAdsr;
    ReverbComponent reverb;
    MeterComponent meter;
    juce::ImageComponent logo;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapSynthAudioProcessorEditor)
};
