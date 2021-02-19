/*
  ==============================================================================

    ReverbComponent.h
    Created: 19 Feb 2021 9:18:11pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ReverbComponent  : public juce::Component
{
public:
    ReverbComponent (juce::AudioProcessorValueTreeState& apvts, juce::String sizeId, juce::String dampingId, juce::String widthId, juce::String dryId, juce::String wetId, juce::String freezeId);
    ~ReverbComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    void setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts);
    
    juce::Slider sizeSlider;
    juce::Slider dampingSlider;
    juce::Slider widthSlider;
    juce::Slider drySlider;
    juce::Slider wetSlider;
    juce::Slider freezeSlider;
    
    juce::Label sizeLabel { "Size", "Size" };
    juce::Label dampingLabel { "Damping", "Damping" };
    juce::Label widthLabel { "Width", "Width" };
    juce::Label dryLabel { "Dry", "Dry" };
    juce::Label wetLabel { "Wet", "Wet" };
    juce::Label freezeLabel { "Freeze", "Freeze" };
    
    std::unique_ptr<SliderAttachment> sizeAttachment;
    std::unique_ptr<SliderAttachment> dampingAttachment;
    std::unique_ptr<SliderAttachment> widthAttachment;
    std::unique_ptr<SliderAttachment> wetAttachment;
    std::unique_ptr<SliderAttachment> dryAttachment;
    std::unique_ptr<SliderAttachment> freezeAttachment;
    
    static constexpr float fontHeight { 15.0f };
    static constexpr int textBoxWidth { 35 };
    static constexpr int textBoxHeight { 20 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbComponent)
};
