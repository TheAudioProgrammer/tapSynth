/*
  ==============================================================================

    SynthVoice.h
    Created: 10 Dec 2020 1:55:41pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "Data/OscData.h"
#include "Data/AdsrData.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound (juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved (int newPitchWheelValue) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override;
    
    OscData& getOscillator1() { return osc1; }
    OscData& getOscillator2() { return osc2; }
    AdsrData& getAdsr() { return adsr; }
    
private:
    OscData osc1;
    OscData osc2;
    AdsrData adsr;
    juce::AudioBuffer<float> synthBuffer;
    
    juce::dsp::Gain<float> gain;
    bool isPrepared { false };
};
