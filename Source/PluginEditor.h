/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"

#include "PluginProcessor.h"
#include "UI/BypassLookAndFeel.h"
#include "UI/BasicKnobLF.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    ANOTHER REMINDER:
        DO NOT EDIT WHERE IT IS NOT MARKED FOR USER CODE!!!
                                                                    //[/Comments]
*/
class ParagraphicEqAudioProcessorEditor  : public AudioProcessorEditor,
                                           public Button::Listener,
                                           public Slider::Listener
{
public:
    //==============================================================================
    ParagraphicEqAudioProcessorEditor (ParagraphicEqAudioProcessor& ownerProc);
    ~ParagraphicEqAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void buttonClicked(Button* buttonThatWasClicked) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;
    using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

    ScopedPointer<SliderAttachment> frequencyKnobAttachments[NUM_BANDS];
    ScopedPointer<SliderAttachment> gainKnobAttachments[NUM_BANDS];

    BasicKnobLF basicKnobLow;
    BasicKnobLF basicKnobMid;
    BasicKnobLF basicKnobHigh;

    ParagraphicEqAudioProcessor& processor;

    // hard coding a bypass button because my bypass look and feel doesn't work too well with
    // the gui builder
    TextButton bypassButton;
    ScopedPointer<ButtonAttachment> bypassAttachment;
    BypassLookAndFeel bypassLF;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> highFreqKnob;
    ScopedPointer<Slider> highGainKnob;
    ScopedPointer<Slider> highMidFreqKnob;
    ScopedPointer<Slider> highMidGainKnob;
    ScopedPointer<Slider> lowMidFreqKnob;
    ScopedPointer<Slider> lowMidGainKnob;
    ScopedPointer<Slider> lowFreqKnob;
    ScopedPointer<Slider> lowGainKnob;
    ScopedPointer<Label> highRangeLabel;
    ScopedPointer<Label> highRangeLabel2;
    ScopedPointer<Label> highRangeLabel3;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParagraphicEqAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
