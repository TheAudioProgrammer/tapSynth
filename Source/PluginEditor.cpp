/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapSynthAudioProcessorEditor::TapSynthAudioProcessorEditor (TapSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), osc1 (audioProcessor.apvts, "OSC1", "OSC1GAIN", "OSC1PITCH"), osc2 (audioProcessor.apvts, "OSC2", "OSC2GAIN", "OSC2PITCH"), adsr (audioProcessor.apvts)
{
    setSize (400, 300);
    addAndMakeVisible (osc1);
    addAndMakeVisible (osc2);
    addAndMakeVisible (adsr);
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
    adsr.setBounds (getWidth() / 2, 0, getWidth() / 2, getHeight());
    osc1.setBounds (0, 25, getWidth() / 2, 100);
    osc2.setBounds (0, 150, getHeight() / 2, 100);
}


