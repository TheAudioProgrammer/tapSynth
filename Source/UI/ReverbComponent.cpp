/*
  ==============================================================================

    ReverbComponent.cpp
    Created: 19 Feb 2021 9:18:11pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ReverbComponent.h"

//==============================================================================
ReverbComponent::ReverbComponent (juce::AudioProcessorValueTreeState& apvts, juce::String sizeId, juce::String dampingId, juce::String widthId, juce::String dryId, juce::String wetId, juce::String freezeId)
{
    setSliderParams (sizeSlider, sizeLabel, sizeAttachment, sizeId, apvts);
    setSliderParams (dampingSlider, dampingLabel, dampingAttachment, dampingId, apvts);
    setSliderParams (widthSlider, widthLabel, widthAttachment, widthId, apvts);
    setSliderParams (drySlider, dryLabel, dryAttachment, dryId, apvts);
    setSliderParams (wetSlider, wetLabel, wetAttachment, wetId, apvts);
    setSliderParams (freezeSlider, freezeLabel, freezeAttachment, freezeId, apvts);
}

ReverbComponent::~ReverbComponent()
{
}

void ReverbComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    auto bounds = getLocalBounds();
    g.setColour (juce::Colours::white);
    g.drawRoundedRectangle (bounds.toFloat().reduced (10.0f), 5.0f, 2.0f);
    
    g.setColour (juce::Colours::yellow);
    g.setFont (fontHeight);
    g.setFont (g.getCurrentFont().boldened());
    g.drawText ("Reverb", 20, 15, 100, 25, juce::Justification::left);
}

void ReverbComponent::resized()
{
    const auto dialSize = 67;
    const auto labelWidth = 67;
    const auto labelHeight = 18;
    const auto yLabelStart = 40;
    const auto yDialStart = 55;
    
    
    sizeLabel.setBounds (5, yLabelStart, labelWidth, labelHeight);
    sizeSlider.setBounds (5, yDialStart, dialSize, dialSize);
    
    dampingLabel.setBounds (sizeLabel.getRight(), yLabelStart, labelWidth, labelHeight);
    dampingSlider.setBounds (sizeSlider.getRight(), yDialStart, dialSize, dialSize);
    
    widthLabel.setBounds (dampingLabel.getRight(), yLabelStart, labelWidth, labelHeight);
    widthSlider.setBounds (dampingSlider.getRight(), yDialStart, dialSize, dialSize);
    
    dryLabel.setBounds (widthLabel.getRight(), yLabelStart, labelWidth, labelHeight);
    drySlider.setBounds (widthSlider.getRight(), yDialStart, dialSize, dialSize);
    
    wetLabel.setBounds (dryLabel.getRight(), yLabelStart, labelWidth, labelHeight);
    wetSlider.setBounds (drySlider.getRight(), yDialStart, dialSize, dialSize);
    
    freezeLabel.setBounds (wetLabel.getRight(), yLabelStart, labelWidth, labelHeight);
    freezeSlider.setBounds (wetSlider.getRight(), yDialStart, dialSize, dialSize);
    
//    pitchLabel.setBounds (190, 15, labelWidth, labelHeight);
//    pitchSlider.setBounds (190, 30, dialSize, dialSize);
//
//    fmFreqLabel.setBounds (260, 15, labelWidth, labelHeight);
//    fmFreqSlider.setBounds (260, 30, dialSize, dialSize);
//
//    fmDepthLabel.setBounds (330, 15, labelWidth, labelHeight);
//    fmDepthSlider.setBounds (330, 30, dialSize, dialSize);
}

using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void ReverbComponent::setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts)
{
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, textBoxWidth, textBoxHeight);
    addAndMakeVisible (slider);
    
    label.setFont (fontHeight);
    label.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (label);
    
    attachment = std::make_unique<SliderAttachment>(apvts, paramId, slider);
}
