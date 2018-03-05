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
    basicKnobLow.setColour(Colour(32, 32, 32));
	basicKnobLowMid.setColour(Colour(128, 128, 128));
    basicKnobHighMid.setColour(Colour(160, 160, 160));
    basicKnobHigh.setColour(Colour(224, 224, 224));

    addAndMakeVisible(bypassButton);
    bypassButton.addListener(this);
    bypassButton.setLookAndFeel(&bypassLF);
    bypassButton.setClickingTogglesState(true);
    //[/Constructor_pre]

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("EQ")));
    label2->setFont (Font ("PMingLiU-ExtB", 45.50f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.105f));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (336, 32, 75, 48);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Paragraphic")));
    label->setFont (Font ("PMingLiU-ExtB", 42.10f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.004f));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (184, -5, 200, 48);

    addAndMakeVisible (hzLabel = new Label ("Hertz Label",
                                            TRANS("Hz")));
    hzLabel->setFont (Font ("URW Gothic L", 22.40f, Font::plain).withTypefaceStyle ("Regular"));
    hzLabel->setJustificationType (Justification::centred);
    hzLabel->setEditable (false, false, false);
    hzLabel->setColour (Label::backgroundColourId, Colour (0x39000000));
    hzLabel->setColour (Label::outlineColourId, Colours::black);
    hzLabel->setColour (TextEditor::textColourId, Colours::black);
    hzLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    hzLabel->setBounds (8, 56, 40, 25);

    addAndMakeVisible (dbLabel = new Label ("Decibel Label",
                                            TRANS("dB")));
    dbLabel->setFont (Font ("URW Gothic L", 22.40f, Font::plain).withTypefaceStyle ("Regular"));
    dbLabel->setJustificationType (Justification::centred);
    dbLabel->setEditable (false, false, false);
    dbLabel->setColour (Label::backgroundColourId, Colour (0x39000000));
    dbLabel->setColour (Label::outlineColourId, Colours::black);
    dbLabel->setColour (TextEditor::textColourId, Colours::black);
    dbLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    dbLabel->setBounds (8, 160, 40, 25);

    addAndMakeVisible (highFreqKnob = new Slider ("High Frequency Knob"));
    highFreqKnob->setRange (0, 10, 0);
    highFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highFreqKnob->addListener (this);

    highFreqKnob->setBounds (590, 50, 125, 100);

    addAndMakeVisible (highGainKnob = new Slider ("High Gain Knob"));
    highGainKnob->setRange (0, 10, 0);
    highGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highGainKnob->addListener (this);

    highGainKnob->setBounds (590, 160, 125, 100);

    addAndMakeVisible (highMidFreqKnob = new Slider ("High-Mid Frequency Knob"));
    highMidFreqKnob->setRange (0, 10, 0);
    highMidFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highMidFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highMidFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highMidFreqKnob->addListener (this);

    highMidFreqKnob->setBounds (410, 50, 125, 100);

    addAndMakeVisible (highMidGainKnob = new Slider ("High-Mid Gain Knob"));
    highMidGainKnob->setRange (0, 10, 0);
    highMidGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    highMidGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    highMidGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    highMidGainKnob->addListener (this);

    highMidGainKnob->setBounds (410, 160, 125, 100);

    addAndMakeVisible (lowMidFreqKnob = new Slider ("Low-Mid Frequency Knob"));
    lowMidFreqKnob->setRange (0, 10, 0);
    lowMidFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowMidFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowMidFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowMidFreqKnob->addListener (this);

    lowMidFreqKnob->setBounds (210, 50, 125, 100);

    addAndMakeVisible (lowMidGainKnob = new Slider ("Low-Mid Gain Knob"));
    lowMidGainKnob->setRange (0, 10, 0);
    lowMidGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowMidGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowMidGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowMidGainKnob->addListener (this);

    lowMidGainKnob->setBounds (210, 160, 125, 100);

    addAndMakeVisible (lowFreqKnob = new Slider ("Low Frequency Knob"));
    lowFreqKnob->setRange (0, 10, 0);
    lowFreqKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowFreqKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowFreqKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowFreqKnob->addListener (this);

    lowFreqKnob->setBounds (30, 50, 125, 100);

    addAndMakeVisible (lowGainKnob = new Slider ("Low Gain Knob"));
    lowGainKnob->setRange (0, 10, 0);
    lowGainKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    lowGainKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lowGainKnob->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    lowGainKnob->addListener (this);

    lowGainKnob->setBounds (30, 160, 125, 100);

    addAndMakeVisible (highRangeLabel = new Label ("Label for High Range",
                                                   TRANS("HIGH")));
    highRangeLabel->setFont (Font ("PMingLiU-ExtB", 32.50f, Font::bold).withExtraKerningFactor (0.030f));
    highRangeLabel->setJustificationType (Justification::centred);
    highRangeLabel->setEditable (false, false, false);
    highRangeLabel->setColour (Label::textColourId, Colour (0xffa6a6a6));
    highRangeLabel->setColour (TextEditor::textColourId, Colours::black);
    highRangeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    highRangeLabel->setBounds (590, 270, 125, 30);

    addAndMakeVisible (lowRangeLabel = new Label ("Label for Low Range",
                                                  TRANS("LOW")));
    lowRangeLabel->setFont (Font ("PMingLiU-ExtB", 32.50f, Font::bold).withExtraKerningFactor (-0.005f));
    lowRangeLabel->setJustificationType (Justification::centred);
    lowRangeLabel->setEditable (false, false, false);
    lowRangeLabel->setColour (Label::textColourId, Colours::black);
    lowRangeLabel->setColour (TextEditor::textColourId, Colours::black);
    lowRangeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    lowRangeLabel->setBounds (30, 270, 125, 30);

    addAndMakeVisible (midRangeLabel = new Label ("Label for Mid Range",
                                                  TRANS("MID")));
    midRangeLabel->setFont (Font ("PMingLiU-ExtB", 32.50f, Font::bold).withExtraKerningFactor (0.030f));
    midRangeLabel->setJustificationType (Justification::centred);
    midRangeLabel->setEditable (false, false, false);
    midRangeLabel->setColour (Label::textColourId, Colour (0xff868686));
    midRangeLabel->setColour (TextEditor::textColourId, Colours::black);
    midRangeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    midRangeLabel->setBounds (328, 270, 84, 32);

    addAndMakeVisible (qConstLabel = new Label ("Q Proportionality Constant Label",
                                                TRANS("Q Proportion")));
    qConstLabel->setFont (Font ("Linux Libertine Display O", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    qConstLabel->setJustificationType (Justification::centred);
    qConstLabel->setEditable (false, false, false);
    qConstLabel->setColour (TextEditor::textColourId, Colours::black);
    qConstLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    qConstLabel->setBounds (645, 0, 90, 25);

    addAndMakeVisible (qProportionSLider = new Slider ("Q Factor Proportionality Slider"));
    qProportionSLider->setRange (0, 10, 0);
    qProportionSLider->setSliderStyle (Slider::LinearHorizontal);
    qProportionSLider->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    qProportionSLider->setColour (Slider::thumbColourId, Colours::black);
    qProportionSLider->setColour (Slider::textBoxBackgroundColourId, Colour (0x39000000));
    qProportionSLider->setColour (Slider::textBoxHighlightColourId, Colour (0xff7e8ba1));
    qProportionSLider->setColour (Slider::textBoxOutlineColourId, Colours::black);
    qProportionSLider->addListener (this);

    qProportionSLider->setBounds (645, 25, 90, 30);


    //[UserPreSize]
    lowFreqKnob->setLookAndFeel(&basicKnobLow);
    lowGainKnob->setLookAndFeel(&basicKnobLow);
    lowFreqKnob->setTextValueSuffix(" Hz");
    lowGainKnob->setTextValueSuffix(" dB");

    lowMidFreqKnob->setLookAndFeel(&basicKnobLowMid);
    lowMidGainKnob->setLookAndFeel(&basicKnobLowMid);
    lowMidFreqKnob->setTextValueSuffix(" Hz");
    lowMidGainKnob->setTextValueSuffix(" dB");

    highMidFreqKnob->setLookAndFeel(&basicKnobHighMid);
    highMidGainKnob->setLookAndFeel(&basicKnobHighMid);
    highMidFreqKnob->setTextValueSuffix(" Hz");
    highMidGainKnob->setTextValueSuffix(" dB");

    highFreqKnob->setLookAndFeel(&basicKnobHigh);
    highGainKnob->setLookAndFeel(&basicKnobHigh);
    highFreqKnob->setTextValueSuffix(" Hz");
    highGainKnob->setTextValueSuffix(" dB");

    lowFreqKnob->setPopupDisplayEnabled(true, true, this);
    lowGainKnob->setPopupDisplayEnabled(true, true, this);

    lowMidFreqKnob->setPopupDisplayEnabled(true, true, this);
    lowMidGainKnob->setPopupDisplayEnabled(true, true, this);

    highMidFreqKnob->setPopupDisplayEnabled(true, true, this);
    highMidGainKnob->setPopupDisplayEnabled(true, true, this);

    highFreqKnob->setPopupDisplayEnabled(true, true, this);
    highGainKnob->setPopupDisplayEnabled(true, true, this);
    //[/UserPreSize]

    setSize (745, 310);


    //[Constructor] You can add your own custom stuff here..
    bypassAttachment = new ButtonAttachment(
        processor.getState(),
        "bypass",
        bypassButton
    );
    qProportionAttachment = new SliderAttachment(
        processor.getState(),
        "qProportion",
        *qProportionSLider
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
	bypassButton.setLookAndFeel(nullptr);
	lowFreqKnob->setLookAndFeel(nullptr);
	lowGainKnob->setLookAndFeel(nullptr);
	lowMidFreqKnob->setLookAndFeel(nullptr);
	lowMidGainKnob->setLookAndFeel(nullptr);
	highMidFreqKnob->setLookAndFeel(nullptr);
	highMidGainKnob->setLookAndFeel(nullptr);
	highFreqKnob->setLookAndFeel(nullptr);
	highGainKnob->setLookAndFeel(nullptr);

	for (int i = 0; i < NUM_BANDS; ++i)
	{
		frequencyKnobAttachments[i] = nullptr;
		gainKnobAttachments[i] = nullptr;
	}

    bypassAttachment = nullptr;
    qProportionAttachment = nullptr;
    //[/Destructor_pre]

    label2 = nullptr;
    label = nullptr;
    hzLabel = nullptr;
    dbLabel = nullptr;
    highFreqKnob = nullptr;
    highGainKnob = nullptr;
    highMidFreqKnob = nullptr;
    highMidGainKnob = nullptr;
    lowMidFreqKnob = nullptr;
    lowMidGainKnob = nullptr;
    lowFreqKnob = nullptr;
    lowGainKnob = nullptr;
    highRangeLabel = nullptr;
    lowRangeLabel = nullptr;
    midRangeLabel = nullptr;
    qConstLabel = nullptr;
    qProportionSLider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	/*

	*/
    //[/Destructor]
}

//==============================================================================
void ParagraphicEqAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff344c58));

    {
        int x = 180, y = 0, width = 1, height = 310;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 572, y = 4, width = 1, height = 310;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

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
    else if (sliderThatWasMoved == qProportionSLider)
    {
        //[UserSliderCode_qProportionSLider] -- add your slider handling code here..
        //[/UserSliderCode_qProportionSLider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ParagraphicEqAudioProcessorEditor::buttonClicked(Button* /*buttonThatWasClicked*/)
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
                 fixedSize="0" initialWidth="745" initialHeight="310">
  <BACKGROUND backgroundColour="ff344c58">
    <RECT pos="180 0 1 310" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="572 4 1 310" fill="solid: ff000000" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="7b25f2d252b59d64" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="336 32 75 48" edTextCol="ff000000"
         edBkgCol="0" labelText="EQ" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="PMingLiU-ExtB" fontsize="45.50000000000000000000"
         kerning="-0.10499999999999999611" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="c50597ba0b9a1e96" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="184 -5 200 48" edTextCol="ff000000"
         edBkgCol="0" labelText="Paragraphic" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="PMingLiU-ExtB"
         fontsize="42.10000000000000142109" kerning="-0.00400000000000000008"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Hertz Label" id="1db46764b7f86da6" memberName="hzLabel"
         virtualName="" explicitFocusOrder="0" pos="8 56 40 25" bkgCol="39000000"
         outlineCol="ff000000" edTextCol="ff000000" edBkgCol="0" labelText="Hz"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="URW Gothic L" fontsize="22.39999999999999857891" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Decibel Label" id="8c5ee1363d33903a" memberName="dbLabel"
         virtualName="" explicitFocusOrder="0" pos="8 160 40 25" bkgCol="39000000"
         outlineCol="ff000000" edTextCol="ff000000" edBkgCol="0" labelText="dB"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="URW Gothic L" fontsize="22.39999999999999857891" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="High Frequency Knob" id="a7bb1242d79a5c96" memberName="highFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="590 50 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="High Gain Knob" id="463ce2ce2286ab48" memberName="highGainKnob"
          virtualName="" explicitFocusOrder="0" pos="590 160 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="High-Mid Frequency Knob" id="5b3911f482fdc8a4" memberName="highMidFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="410 50 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="High-Mid Gain Knob" id="6f920767749b8f07" memberName="highMidGainKnob"
          virtualName="" explicitFocusOrder="0" pos="410 160 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low-Mid Frequency Knob" id="dee7fd30a9306ddb" memberName="lowMidFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="210 50 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low-Mid Gain Knob" id="e0551afad609c820" memberName="lowMidGainKnob"
          virtualName="" explicitFocusOrder="0" pos="210 160 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low Frequency Knob" id="80de85f6488c9080" memberName="lowFreqKnob"
          virtualName="" explicitFocusOrder="0" pos="30 50 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <SLIDER name="Low Gain Knob" id="f10c0afe43d512a1" memberName="lowGainKnob"
          virtualName="" explicitFocusOrder="0" pos="30 160 125 100" textboxoutline="8e989b"
          min="0.00000000000000000000" max="10.00000000000000000000" int="0.00000000000000000000"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
          needsCallback="1"/>
  <LABEL name="Label for High Range" id="b0a036be15f31f4d" memberName="highRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="590 270 125 30" textCol="ffa6a6a6"
         edTextCol="ff000000" edBkgCol="0" labelText="HIGH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="PMingLiU-ExtB"
         fontsize="32.50000000000000000000" kerning="0.02999999999999999889"
         bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Label for Low Range" id="8b505350af2aa5e2" memberName="lowRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="30 270 125 30" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="LOW" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="PMingLiU-ExtB"
         fontsize="32.50000000000000000000" kerning="-0.00500000000000000010"
         bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Label for Mid Range" id="160bf294fa86114f" memberName="midRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="328 270 84 32" textCol="ff868686"
         edTextCol="ff000000" edBkgCol="0" labelText="MID" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="PMingLiU-ExtB"
         fontsize="32.50000000000000000000" kerning="0.02999999999999999889"
         bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="Q Proportionality Constant Label" id="9b6feea10da771c4"
         memberName="qConstLabel" virtualName="" explicitFocusOrder="0"
         pos="645 0 90 25" edTextCol="ff000000" edBkgCol="0" labelText="Q Proportion"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Linux Libertine Display O" fontsize="15.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <SLIDER name="Q Factor Proportionality Slider" id="78d0015488cd36f7"
          memberName="qProportionSLider" virtualName="" explicitFocusOrder="0"
          pos="645 25 90 30" thumbcol="ff000000" textboxbkgd="39000000"
          textboxhighlight="ff7e8ba1" textboxoutline="ff000000" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.00000000000000000000" style="LinearHorizontal"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
