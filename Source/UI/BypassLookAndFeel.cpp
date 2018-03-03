/*
  ==============================================================================

    BypassLookAndFeel.cpp
    Created: 7 Aug 2017 3:52:52pm
    Author:  WJ

  ==============================================================================
*/

#include "BypassLookAndFeel.h"

BypassLookAndFeel::BypassLookAndFeel()
{}

BypassLookAndFeel::~BypassLookAndFeel()
{}

void BypassLookAndFeel::drawButtonText(
	Graphics& g,
	TextButton& button,
	bool isMouseOverButton,
	bool isButtonDown
)
{
	const float lineThickness = 1.5f;
	const float fromAngle = 5.0f * float_Pi / 6.0f;
	const float toAngle = -fromAngle;

	Path powerArc;
	powerArc.addArc(
		button.getX() + (button.getWidth() * 0.25f), 
		button.getY() + (button.getHeight() * 0.25f) - 1.5, 
		button.getWidth() * 0.5, 
		button.getHeight() * 0.5,
		fromAngle,
		toAngle,
		true);

	Path powerStick;
	const float length = 15.0f;
	powerStick.addRectangle(
		button.getWidth() * 0.45f + 1.5f,
		button.getHeight() * 0.45f + 1.5f,
		lineThickness,
		length);

	// if bypass is on
	if(button.getToggleState())
	{
		g.setColour(Colours::dimgrey);
	}
	else
	{ 
		g.setColour(Colours::limegreen);
	}

	g.strokePath(powerArc, PathStrokeType(lineThickness));
	g.fillPath(powerStick);
}