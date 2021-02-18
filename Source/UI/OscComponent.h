/*
  ==============================================================================

    OscComponent.h
    Created: 14 Feb 2021 6:51:39pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OscComponent : public juce::Component
{
public:
    OscComponent (juce::AudioProcessorValueTreeState& apvts, juce::String oscId, juce::String gainId, juce::String pitchId, juce::String fmPitchId, juce::String fmFreqId);
    ~OscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void setName (const juce::String n) { name = n; }

private:
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    void setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<sliderAttachment>&, juce::String paramId, juce::AudioProcessorValueTreeState& apvts);
    
    juce::ComboBox oscSelector;
    juce::Slider gainSlider;
    juce::Slider pitchSlider;
    juce::Slider fmFreqSlider;
    juce::Slider fmDepthSlider;
    
    juce::Label gainLabel { "Gain", "Gain" };
    juce::Label pitchLabel { "Pitch", "Pitch" };
    juce::Label fmFreqLabel { "FM Freq", "FM Freq" };
    juce::Label fmDepthLabel { "FM Depth", "FM Depth" };
        
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelAttachment;
    std::unique_ptr<sliderAttachment> gainAttachment;
    std::unique_ptr<sliderAttachment> pitchAttachment;
    std::unique_ptr<sliderAttachment> fmFreqAttachment;
    std::unique_ptr<sliderAttachment> fmDepthAttachment;
    
    juce::String name { "" };
    
    static constexpr float fontHeight { 15.0f };
    static constexpr int textBoxWidth { 35 };
    static constexpr int textBoxHeight { 20 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
