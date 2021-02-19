/*
  ==============================================================================

    SynthVoice.cpp
    Created: 10 Dec 2020 1:55:41pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include "SynthVoice.h"


bool SynthVoice::canPlaySound (juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition)
{
    for (int i = 0; i < 2; i++)
    {
        osc1[i].setFreq (midiNoteNumber);
        osc2[i].setFreq (midiNoteNumber);
    }
    
    adsr.noteOn();
    filterAdsr.noteOn();
}

void SynthVoice::stopNote (float velocity, bool allowTailOff)
{
    adsr.noteOff();
    filterAdsr.noteOff();
    
    if (! allowTailOff || ! adsr.isActive())
        clearCurrentNote();
}

void SynthVoice::controllerMoved (int controllerNumber, int newControllerValue)
{
    
}

void SynthVoice::pitchWheelMoved (int newPitchWheelValue)
{
    
}

void SynthVoice::prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels)
{
    adsr.setSampleRate (sampleRate);
    filterAdsr.setSampleRate (sampleRate);
    
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    
    for (int i = 0; i < 2; i++)
    {
        osc1[i].prepareToPlay (sampleRate, samplesPerBlock, outputChannels);
        osc2[i].prepareToPlay (sampleRate, samplesPerBlock, outputChannels);
    }
    
    gain.prepare (spec);
    gain.setGainLinear (0.07f);
    
    isPrepared = true;
}

void SynthVoice::renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
{
    jassert (isPrepared);
    
    if (! isVoiceActive())
        return;
    
    synthBuffer.setSize (outputBuffer.getNumChannels(), numSamples, false, false, true);
    
    filterAdsr.applyEnvelopeToBuffer (synthBuffer, 0, synthBuffer.getNumSamples());
    filterAdsrOutput = filterAdsr.getNextSample();
    
    synthBuffer.clear();
    
    for (int i = 0; i < synthBuffer.getNumChannels(); ++i)
    {
        auto* buffer = synthBuffer.getWritePointer (i, 0);
        
        for (int j = 0; j < synthBuffer.getNumSamples(); ++j)
        {
            buffer[j] = osc1[i].processNextSample (buffer[j]) + osc2[i].processNextSample (buffer[j]);
        }
    }
    
    juce::dsp::AudioBlock<float> audioBlock { synthBuffer };
    
    gain.process (juce::dsp::ProcessContextReplacing<float> (audioBlock));

    adsr.applyEnvelopeToBuffer (synthBuffer, 0, synthBuffer.getNumSamples());
    
    for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
    {
        outputBuffer.addFrom (channel, startSample, synthBuffer, channel, 0, numSamples);
        
        if (! adsr.isActive())
            clearCurrentNote();
    }
}
