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
, osc1 (audioProcessor.apvts, "OSC1", "OSC1GAIN", "OSC1PITCH", "OSC1FMFREQ", "OSC1FMDEPTH")
, osc2 (audioProcessor.apvts, "OSC2", "OSC2GAIN", "OSC2PITCH", "OSC2FMFREQ", "OSC2FMDEPTH")
, adsr (audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE")
{
    setSize (650, 240);
    addAndMakeVisible (osc1);
    addAndMakeVisible (osc2);
    addAndMakeVisible (adsr);
    
    osc1.setName ("Oscillator 1");
    osc2.setName ("Oscillator 2");
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
    const auto oscWidth = 420;
    const auto oscHeight = 120;
    osc1.setBounds (0, 0, oscWidth, oscHeight);
    osc2.setBounds (0, osc1.getBottom(), oscWidth, oscHeight);
    adsr.setBounds (osc1.getRight(), 0, 230, 240);
}


