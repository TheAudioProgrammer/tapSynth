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
, filter (audioProcessor.apvts, "FILTERTYPE", "FILTERCUTOFF", "FILTERRESONANCE")
, adsr (audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE")
, lfo1 (audioProcessor.apvts, "LFO1FREQ", "LFO1DEPTH")
, filterAdsr (audioProcessor.apvts, "FILTERATTACK", "FILTERDECAY", "FILTERSUSTAIN", "FILTERRELEASE")
, reverb (audioProcessor.apvts, "REVERBSIZE", "REVERBDAMPING", "REVERBWIDTH", "REVERBDRY", "REVERBWET", "REVERBFREEZE")
, meter (audioProcessor)
{
    auto tapImage = juce::ImageCache::getFromMemory (BinaryData::tapLogo_png, BinaryData::tapLogo_pngSize);
    
    if (tapImage.isValid())
        logo.setImage (tapImage, juce::RectanglePlacement::stretchToFit);
    else
        jassertfalse;
    
    addAndMakeVisible (osc1);
    addAndMakeVisible (osc2);
    addAndMakeVisible (filter);
    addAndMakeVisible (adsr);
    addAndMakeVisible (lfo1);
    addAndMakeVisible (filterAdsr);
    addAndMakeVisible (reverb);
    addAndMakeVisible (meter);
    addAndMakeVisible (logo);
    
    osc1.setName ("Oscillator 1");
    osc2.setName ("Oscillator 2");
    filter.setName ("Filter");
    lfo1.setName ("Filter LFO");
    filterAdsr.setName ("Filter ADSR");
    adsr.setName ("ADSR");
    meter.setName ("Meter");
    
    auto oscColour = juce::Colour::fromRGB (247, 190, 67);
    auto filterColour = juce::Colour::fromRGB (246, 87, 64);
    
    osc1.setBoundsColour (oscColour);
    osc2.setBoundsColour (oscColour);
    
    filterAdsr.setBoundsColour (filterColour);
    filter.setBoundsColour (filterColour);
    lfo1.setBoundsColour (filterColour);
        
    
    startTimerHz (30);
    setSize (1080, 525);
}

TapSynthAudioProcessorEditor::~TapSynthAudioProcessorEditor()
{
    stopTimer();
}

//==============================================================================
void TapSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void TapSynthAudioProcessorEditor::resized()
{
    const auto oscWidth = 420;
    const auto oscHeight = 180;
    osc1.setBounds (0, 0, oscWidth, oscHeight);
    osc2.setBounds (0, osc1.getBottom(), oscWidth, oscHeight);
    filter.setBounds (osc1.getRight(), 0, 180, 200);
    lfo1.setBounds (osc2.getRight(), filter.getBottom(), 180, 160);
    filterAdsr.setBounds (filter.getRight(), 0, 230, 360);
    adsr.setBounds (filterAdsr.getRight(), 0, 230, 360);
    reverb.setBounds (0, osc2.getBottom(), oscWidth, 150);
    meter.setBounds (reverb.getRight(), osc2.getBottom(), filterAdsr.getWidth() + lfo1.getWidth(), 150);
    logo.setBounds (meter.getRight(), osc2.getBottom() + 30, 250, 100);
}

void TapSynthAudioProcessorEditor::timerCallback()
{
    repaint();
}
