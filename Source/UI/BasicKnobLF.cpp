/*
  ==============================================================================

    BasicKnobLF.cpp
    Created: 9 Aug 2017 11:14:27am
    Author:  WJ

  ==============================================================================
*/

#include "BasicKnobLF.h"

BasicKnobLF::BasicKnobLF()
	: brushColour {Colours::deepskyblue}
{}

BasicKnobLF::~BasicKnobLF()
{}

// just some tweaking to the standard rotary
void BasicKnobLF::drawRotarySlider(
	Graphics& g, int x, int y, int width, int height, float sliderPos,
	const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
	const auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(10);

	auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;
	const auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
	auto lineW = rotaryThickness; //jmin(8.0f, radius * 0.5f);

	const float centerX = x + width * 0.5f;
	const float centerY = y + height * 0.5f;
        const float rx = centerX - radius;
        const float ry = centerY - radius;
        const float rw = radius * 2.0f;

        // Plain Black Knob
        g.setColour(brushColour);
        g.fillEllipse(rx, ry, rw, rw);

	Path needle;
	const float pointerLength = radius * 0.5f;
	const float pointerThickness = 2.5f;
	needle.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
	needle.applyTransform(AffineTransform::rotation(toAngle).translated(centerX, centerY));

	g.setColour(Colours::white);
	g.fillPath(needle);

//	Path knob;
//	knob.addEllipse(x, y, width, height);
}

Label* BasicKnobLF::createSliderTextBox(Slider& slider)
{
	auto sliderLabel = new Label();

	Font newFont;
	newFont.setStyleFlags(2);
//	newFont.setHeight(15.0f);

	sliderLabel->setJustificationType(Justification::centred);
	sliderLabel->setKeyboardType(TextInputTarget::decimalKeyboard);

	sliderLabel->setColour(Label::textColourId, Colours::whitesmoke);
	sliderLabel->setFont(newFont);
	sliderLabel->setEditable(false, true);


	return sliderLabel;
}
