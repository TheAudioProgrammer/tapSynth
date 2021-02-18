/*
  ==============================================================================

    FilterComponent.h
    Created: 18 Feb 2021 10:00:39pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FilterComponent : public juce::Component
{
public:
    FilterComponent (juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeId, juce::String cutoffId, juce::String resonanceId);
    ~FilterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void setName (const juce::String n) { name = n; }

private:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    void setSliderParams (juce::Slider& slider, juce::Label& label, std::unique_ptr<SliderAttachment>& attachment, juce::String paramId, juce::AudioProcessorValueTreeState& apvts);
    
    juce::ComboBox filterTypeSelector;
    juce::Slider cutoffSlider;
    juce::Slider resonanceSlider;
    
    juce::Label cutoffLabel { "Cutoff", "Cutoff" };
    juce::Label resonanceLabel { "Resonance", "Resonance" };
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeAttachment;
    std::unique_ptr<SliderAttachment> cutoffAttachment;
    std::unique_ptr<SliderAttachment> resonanceAttachment;
    
    juce::String name { "" };
    static constexpr float fontHeight { 15.0f };
    static constexpr int textBoxWidth { 50 };
    static constexpr int textBoxHeight { 20 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
