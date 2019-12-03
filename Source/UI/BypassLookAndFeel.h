#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class BypassLookAndFeel 
	: public LookAndFeel_V4
{
public:
	BypassLookAndFeel();
	~BypassLookAndFeel();

	void drawButtonText(
		Graphics& g,
		TextButton& button,
		bool isMouseOverButton,
		bool isButtonDown) override;
};
