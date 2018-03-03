/*
  ==============================================================================

    BasicKnobLF.h
    Created: 9 Aug 2017 11:14:27am
    Author:  WJ

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class BasicKnobLF : public LookAndFeel_V4
{
public:
	BasicKnobLF();
	~BasicKnobLF();

	void setColour(Colour newColour)
	{
		brushColour = newColour;
	}
	void setRotaryThickness(float newThickness)
	{
		rotaryThickness = newThickness;
	}

	void drawRotarySlider(
		Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) 
		override;

	Label* createSliderTextBox(Slider& slider) override;

private:
	Colour brushColour;
	float rotaryThickness;
};
