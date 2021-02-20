/*
  ==============================================================================

    CustomComponent.h
    Created: 20 Feb 2021 9:51:27am
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/

static constexpr float fontHeight { 15.0f };

class SliderWithLabel : public juce::Component
{
public:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using SliderStyle = juce::Slider::SliderStyle;
    
    SliderWithLabel (juce::String labelName, juce::String paramId, juce::AudioProcessorValueTreeState& apvts, const int width, const int height, SliderStyle style = SliderStyle::RotaryHorizontalVerticalDrag);
        
    void resized() override;
    
private:
    static constexpr int textBoxWidth { 48 };
    static constexpr int textBoxHeight { 20 };
    int sliderWidth { 0 };
    int sliderHeight { 0 };
    juce::Slider slider;
    juce::Label label;
    std::unique_ptr<SliderAttachment> attachment;
};

class CustomComponent  : public juce::Component
{
public:
    CustomComponent();
    ~CustomComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void setName (juce::String n) { name = n; }
    void setBoundsColour (juce::Colour c) { boundsColour = c; }

private:
    juce::String name { "" };
    juce::Colour boundsColour { juce::Colours::white };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomComponent)
};
