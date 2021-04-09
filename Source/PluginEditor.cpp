/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapSynthAudioProcessorEditor::TapSynthAudioProcessorEditor (TapSynthAudioProcessor& p)
: AudioProcessorEditor (&p)
, audioProcessor (p)
, osc (audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH")
, adsr ("Amp Envelope", audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE")
, filterAdsr ("Mod Envelope", audioProcessor.apvts, "FILTERATTACK", "FILTERDECAY", "FILTERSUSTAIN", "FILTERRELEASE")
, filter (audioProcessor.apvts, "FILTERTYPE", "FILTERFREQ", "FILTERRES")
{
    setSize (620, 500);
    addAndMakeVisible (osc);
    addAndMakeVisible (adsr);
    addAndMakeVisible (filterAdsr);
    addAndMakeVisible (filter);
}

TapSynthAudioProcessorEditor::~TapSynthAudioProcessorEditor()
{
}

//==============================================================================
void TapSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void TapSynthAudioProcessorEditor::resized()
{
    const auto paddingX = 5;
    const auto paddingY = 35;
    const auto paddingY2 = 235;
    
    osc.setBounds (paddingX, paddingY, 300, 200);
    adsr.setBounds (osc.getRight(), paddingY, 300, 200);
    filterAdsr.setBounds (paddingX, paddingY2, 300, 200);
    filter.setBounds (filterAdsr.getRight(), paddingY2, 300, 200);
}


