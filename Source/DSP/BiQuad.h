#pragma once

#include <iostream>

static constexpr double PI = 3.14159;

enum FilterType
{
	PEAK, // 0
	LOW_PASS,
	HIGH_PASS
};

class BiQuad
{
public:
	BiQuad();
	BiQuad(FilterType ftype); 
	~BiQuad();

	void calculateCoefficients(float fs, float f0, float gain, float Q = 2);
	void process(float* buffer, float numSamples);
	float process(float sampleData);

	FilterType getType()
	{
		return type;
	}

	void reset()
	{
		xn_1 = xn_2 = yn_1 = yn_2 = 0;
	}

	void changeType(FilterType ftype)
	{
		type = ftype;
	}

private:
	FilterType type;

	// Filter Coefficients
	float a1, a2;
	float b0, b1, b2;

	// Delay 
	float xn_1, xn_2;
	float yn_1, yn_2;
};
