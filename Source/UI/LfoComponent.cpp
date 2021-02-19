/*
  ==============================================================================

    LfoComponent.cpp
    Created: 19 Feb 2021 8:12:35pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LfoComponent.h"

//==============================================================================
LfoComponent::LfoComponent (juce::AudioProcessorValueTreeState& apvts, juce::String lfoFreqId, juce::String lfoDepthId)
{
    setSliderParams (lfoFreqSlider, lfoFreqLabel, lfoFreqAttachment, lfoFreqId, apvts);
    setSliderParams (lfoDepthSlider, lfoDepthLabel, lfoDepthAttachment, lfoDepthId, apvts);
}

LfoComponent::~LfoComponent()
{
}

void LfoComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    auto bounds = getLocalBounds();
    g.setColour (juce::Colours::white);
    g.drawRoundedRectangle (bounds.toFloat().reduced (10.0f), 5.0f, 2.0f);
    
    g.setColour (juce::Colours::yellow);
    g.setFont (fontHeight);
    g.setFont (g.getCurrentFont().boldened());
    g.drawText ("Filter LFO", 20, 15, 100, 25, juce::Justification::left);
}

void LfoComponent::resized()
{
    const auto dialSize = 70;
    const auto labelWidth = 70;
    const auto labelHeight = 18;
        
    lfoFreqLabel.setBounds (18, 40, labelWidth, labelHeight);
    lfoFreqSlider.setBounds (18, 55, dialSize, dialSize);
    lfoDepthLabel.setBounds (90, 40, labelWidth, labelHeight);
    lfoDepthSlider.setBounds (90, 55, dialSize, dialSize);
}

void LfoComponent::setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    addAndMakeVisible (slider);
    
    label.setFont (fontHeight);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
    
    attachment = std::make_unique<SliderAttachment>(apvts, paramId, slider);
}
