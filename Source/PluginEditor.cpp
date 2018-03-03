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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ParagraphicEqAudioProcessorEditor::ParagraphicEqAudioProcessorEditor (ParagraphicEqAudioProcessor& ownerProc)
    : AudioProcessorEditor(&ownerProc), processor(ownerProc)
{
    //[Constructor_pre] You can add your own custom stuff here..
    basicKnobLow.setColour(Colours::black);
    basicKnobMid.setColour(Colour(86, 86, 86));
    basicKnobHigh.setColour(Colour(0xffa6a6a6));

    addAndMakeVisible(bypassButton);
    bypassButton.addListener(this);
    bypassButton.setLookAndFeel(&bypassLF);
    bypassButton.setClickingTogglesState(true);
    //[/Constructor_pre]

    addAndMakeVisible (highFreqKnob = new Slider ("High Frequency Knob"));
    highFreqKnob->setRange (0, 10, 0);
    highFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highFreqKnob->addListener (this);

    highFreqKnob->setBounds (125, 50, 125, 100);

    addAndMakeVisible (highGainKnob = new Slider ("High Gain Knob"));
    highGainKnob->setRange (0, 10, 0);
    highGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highGainKnob->addListener (this);

    highGainKnob->setBounds (0, 120, 125, 100);

    addAndMakeVisible (highMidFreqKnob = new Slider ("High-Mid Frequency Knob"));
    highMidFreqKnob->setRange (0, 10, 0);
    highMidFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highMidFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highMidFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highMidFreqKnob->addListener (this);

    highMidFreqKnob->setBounds (125, 195, 125, 100);

    addAndMakeVisible (highMidGainKnob = new Slider ("High-Mid Gain Knob"));
    highMidGainKnob->setRange (0, 10, 0);
    highMidGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highMidGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highMidGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highMidGainKnob->addListener (this);

    highMidGainKnob->setBounds (0, 265, 125, 100);

    addAndMakeVisible (lowMidFreqKnob = new Slider ("Low-Mid Frequency Knob"));
    lowMidFreqKnob->setRange (0, 10, 0);
    lowMidFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowMidFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowMidFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowMidFreqKnob->addListener (this);

    lowMidFreqKnob->setBounds (125, 340, 125, 100);

    addAndMakeVisible (lowMidGainKnob = new Slider ("Low-Mid Gain Knob"));
    lowMidGainKnob->setRange (0, 10, 0);
    lowMidGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowMidGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowMidGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowMidGainKnob->addListener (this);

    lowMidGainKnob->setBounds (0, 410, 125, 100);

    addAndMakeVisible (lowFreqKnob = new Slider ("Low Frequency Knob"));
    lowFreqKnob->setRange (0, 10, 0);
    lowFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowFreqKnob->addListener (this);

    lowFreqKnob->setBounds (125, 485, 125, 100);

    addAndMakeVisible (lowGainKnob = new Slider ("Low Gain Knob"));
    lowGainKnob->setRange (0, 10, 0);
    lowGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowGainKnob->addListener (this);

    lowGainKnob->setBounds (0, 555, 125, 100);

    addAndMakeVisible (highRangeLabel = new Label ("Label for High Range",
                                                   TRANS("HIGH")));
    highRangeLabel->setFont (Font ("Linux Libertine Initials O", 32.50f, Font::plain).withExtraKerningFactor (0.030f));
    highRangeLabel->setJustificationType (Justification::centred);
    highRangeLabel->setEditable (false, false, false);
    highRangeLabel->setColour (Label::textColourId, Colour (0xffa6a6a6));
    highRangeLabel->setColour (TextEditor::textColourId, Colours::black);
    highRangeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    highRangeLabel->setBounds (0, 72, 128, 32);

    addAndMakeVisible (highRangeLabel2 = new Label ("Label for High Range",
                                                    TRANS("LOW")));
    highRangeLabel2->setFont (Font ("Linux Libertine Initials O", 32.50f, Font::plain).withExtraKerningFactor (0.030f));
    highRangeLabel2->setJustificationType (Justification::centred);
    highRangeLabel2->setEditable (false, false, false);
    highRangeLabel2->setColour (Label::textColourId, Colours::black);
    highRangeLabel2->setColour (TextEditor::textColourId, Colours::black);
    highRangeLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    highRangeLabel2->setBounds (144, 608, 84, 32);

    addAndMakeVisible (highRangeLabel3 = new Label ("Label for High Range",
                                                    TRANS("MID")));
    highRangeLabel3->setFont (Font ("Linux Libertine Initials O", 32.50f, Font::plain).withExtraKerningFactor (0.030f));
    highRangeLabel3->setJustificationType (Justification::centred);
    highRangeLabel3->setEditable (false, false, false);
    highRangeLabel3->setColour (Label::textColourId, Colour (0xff868686));
    highRangeLabel3->setColour (TextEditor::textColourId, Colours::black);
    highRangeLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    highRangeLabel3->setBounds (48, 368, 84, 32);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Paragraphic")));
    label->setFont (Font ("Linux Biolinum Keyboard O", 27.80f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.004f));
    label->setJustificationType (Justification::topLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (0, 696, 250, 32);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("EQ")));
    label2->setFont (Font ("Linux Biolinum Keyboard O", 45.50f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.105f));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (0, 736, 250, 40);


    //[UserPreSize]
    lowFreqKnob->setLookAndFeel(&basicKnobLow);
    lowGainKnob->setLookAndFeel(&basicKnobLow);

    lowMidFreqKnob->setLookAndFeel(&basicKnobMid);
    lowMidGainKnob->setLookAndFeel(&basicKnobMid);

    highMidFreqKnob->setLookAndFeel(&basicKnobMid);
    highMidGainKnob->setLookAndFeel(&basicKnobMid);

    highFreqKnob->setLookAndFeel(&basicKnobHigh);
    highGainKnob->setLookAndFeel(&basicKnobHigh);

    lowFreqKnob->setPopupDisplayEnabled(true, true, this);
    lowGainKnob->setPopupDisplayEnabled(true, true, this);

    lowMidFreqKnob->setPopupDisplayEnabled(true, true, this);
    lowMidGainKnob->setPopupDisplayEnabled(true, true, this);

    highMidFreqKnob->setPopupDisplayEnabled(true, true, this);
    highMidGainKnob->setPopupDisplayEnabled(true, true, this);

    highFreqKnob->setPopupDisplayEnabled(true, true, this);
    highGainKnob->setPopupDisplayEnabled(true, true, this);
    //[/UserPreSize]

    setSize (250, 800);


    //[Constructor] You can add your own custom stuff here..
    bypassAttachment = new ButtonAttachment(
        processor.getState(),
        "bypass",
        bypassButton
    );

    // Band Gain and Freq Attachments
    frequencyKnobAttachments[FrequencyRange::LOW] = new SliderAttachment(
        processor.getState(),
        processor.freqParameterIDs[FrequencyRange::LOW],
        *lowFreqKnob
    );
    frequencyKnobAttachments[FrequencyRange::LOW_MID] = new SliderAttachment(
        processor.getState(),
        processor.freqParameterIDs[FrequencyRange::LOW_MID],
        *lowMidFreqKnob
    );
    frequencyKnobAttachments[FrequencyRange::HIGH_MID] = new SliderAttachment(
        processor.getState(),
        processor.freqParameterIDs[FrequencyRange::HIGH_MID],
        *highMidFreqKnob
    );
    frequencyKnobAttachments[FrequencyRange::HIGH] = new SliderAttachment(
        processor.getState(),
        processor.freqParameterIDs[FrequencyRange::HIGH],
        *highFreqKnob
    );

    gainKnobAttachments[FrequencyRange::LOW] = new SliderAttachment(
        processor.getState(),
        processor.gainParameterIDs[FrequencyRange::LOW],
        *lowGainKnob
    );
    gainKnobAttachments[FrequencyRange::LOW_MID] = new SliderAttachment(
        processor.getState(),
        processor.gainParameterIDs[FrequencyRange::LOW_MID],
        *lowMidGainKnob
    );
    gainKnobAttachments[FrequencyRange::HIGH_MID] = new SliderAttachment(
        processor.getState(),
        processor.gainParameterIDs[FrequencyRange::HIGH_MID],
        *highMidGainKnob
    );
    gainKnobAttachments[FrequencyRange::HIGH] = new SliderAttachment(
        processor.getState(),
        processor.gainParameterIDs[FrequencyRange::HIGH],
        *highGainKnob
    );
    //[/Constructor]
}

ParagraphicEqAudioProcessorEditor::~ParagraphicEqAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    bypassAttachment = nullptr;
    //[/Destructor_pre]

    highFreqKnob = nullptr;
    highGainKnob = nullptr;
    highMidFreqKnob = nullptr;
    highMidGainKnob = nullptr;
    lowMidFreqKnob = nullptr;
    lowMidGainKnob = nullptr;
    lowFreqKnob = nullptr;
    lowGainKnob = nullptr;
    highRangeLabel = nullptr;
    highRangeLabel2 = nullptr;
    highRangeLabel3 = nullptr;
    label = nullptr;
    label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    for(int i = 0; i < NUM_BANDS; ++i)
    {
        frequencyKnobAttachments[i] = nullptr;
        gainKnobAttachments[i] = nullptr;
    }
    //[/Destructor]
}

//==============================================================================
void ParagraphicEqAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff344c58));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParagraphicEqAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    bypassButton.setBounds(Rectangle<int>(0, 0, 40, 40));
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ParagraphicEqAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == highFreqKnob)
    {
        //[UserSliderCode_highFreqKnob] -- add your slider handling code here..
        //[/UserSliderCode_highFreqKnob]
    }
    else if (sliderThatWasMoved == highGainKnob)
    {
        //[UserSliderCode_highGainKnob] -- add your slider handling code here..
        //[/UserSliderCode_highGainKnob]
    }
    else if (sliderThatWasMoved == highMidFreqKnob)
    {
        //[UserSliderCode_highMidFreqKnob] -- add your slider handling code here..
        //[/UserSliderCode_highMidFreqKnob]
    }
    else if (sliderThatWasMoved == highMidGainKnob)
    {
        //[UserSliderCode_highMidGainKnob] -- add your slider handling code here..
        //[/UserSliderCode_highMidGainKnob]
    }
    else if (sliderThatWasMoved == lowMidFreqKnob)
    {
        //[UserSliderCode_lowMidFreqKnob] -- add your slider handling code here..
        //[/UserSliderCode_lowMidFreqKnob]
    }
    else if (sliderThatWasMoved == lowMidGainKnob)
    {
        //[UserSliderCode_lowMidGainKnob] -- add your slider handling code here..
        //[/UserSliderCode_lowMidGainKnob]
    }
    else if (sliderThatWasMoved == lowFreqKnob)
    {
        //[UserSliderCode_lowFreqKnob] -- add your slider handling code here..
        //[/UserSliderCode_lowFreqKnob]
    }
    else if (sliderThatWasMoved == lowGainKnob)
    {
        //[UserSliderCode_lowGainKnob] -- add your slider handling code here..
        //[/UserSliderCode_lowGainKnob]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ParagraphicEqAudioProcessorEditor::buttonClicked(Button* buttonThatWasClicked)
{

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParagraphicEqAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Button::Listener"
                 constructorParams="ParagraphicEqAudioProcessor&amp; ownerProc"
                 variableInitialisers="AudioProcessorEditor(&amp;ownerProc), processor(ownerProc)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="250" initialHeight="800">
  <BACKGROUND backgroundColour="ff344c58"/>
  <SLIDER name="High Frequency Knob" id="a7bb1242d79a5c96" memberName="highFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="125 50 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="High Gain Knob" id="463ce2ce2286ab48" memberName="highGainKnob"
          virtualName="" explicitFocusOrder="0" pos="0 120 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="High-Mid Frequency Knob" id="5b3911f482fdc8a4" memberName="highMidFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="125 195 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="High-Mid Gain Knob" id="6f920767749b8f07" memberName="highMidGainKnob"
          virtualName="" explicitFocusOrder="0" pos="0 265 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low-Mid Frequency Knob" id="dee7fd30a9306ddb" memberName="lowMidFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="125 340 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low-Mid Gain Knob" id="e0551afad609c820" memberName="lowMidGainKnob"
          virtualName="" explicitFocusOrder="0" pos="0 410 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low Frequency Knob" id="80de85f6488c9080" memberName="lowFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="125 485 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low Gain Knob" id="f10c0afe43d512a1" memberName="lowGainKnob"
          virtualName="" explicitFocusOrder="0" pos="0 555 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="Label for High Range" id="b0a036be15f31f4d" memberName="highRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 72 128 32" textCol="ffa6a6a6"
         edTextCol="ff000000" edBkgCol="0" labelText="HIGH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Linux Libertine Initials O"
         fontsize="32.50000000000000000000" kerning="0.02999999999999999889"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Label for High Range" id="8b505350af2aa5e2" memberName="highRangeLabel2"
         virtualName="" explicitFocusOrder="0" pos="144 608 84 32" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LOW" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Linux Libertine Initials O"
         fontsize="32.50000000000000000000" kerning="0.02999999999999999889"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Label for High Range" id="160bf294fa86114f" memberName="highRangeLabel3"
         virtualName="" explicitFocusOrder="0" pos="48 368 84 32" textCol="ff868686"
         edTextCol="ff000000" edBkgCol="0" labelText="MID" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Linux Libertine Initials O"
         fontsize="32.50000000000000000000" kerning="0.02999999999999999889"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="c50597ba0b9a1e96" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 696 250 32" edTextCol="ff000000"
         edBkgCol="0" labelText="Paragraphic" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Linux Biolinum Keyboard O"
         fontsize="27.80000000000000071054" kerning="-0.00400000000000000008"
         bold="0" italic="0" justification="9"/>
  <LABEL name="new label" id="7b25f2d252b59d64" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 736 250 40" edTextCol="ff000000"
         edBkgCol="0" labelText="EQ" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Linux Biolinum Keyboard O"
         fontsize="45.50000000000000000000" kerning="-0.10499999999999999611"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
