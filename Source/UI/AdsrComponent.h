/*
  ==============================================================================

    AdsrComponent.h
    Created: 7 Feb 2021 2:28:49pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrComponent : public juce::Component
{
public:
    AdsrComponent (juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    void setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    
    juce::Label attackLabel { "A", "A" };
    juce::Label decayLabel { "D", "D" };
    juce::Label sustainLabel { "S", "S" };
    juce::Label releaseLabel { "R", "R" };
        
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;
    
    static constexpr float fontHeight { 15.0f };
    static constexpr int textBoxWidth { 35 };
    static constexpr int textBoxHeight { 20 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
