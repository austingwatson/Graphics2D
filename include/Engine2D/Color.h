#pragma once

class Color
{
public:
	Color();
	Color(float r, float g, float b, float a);
	Color(int r, int g, int b, int a);
	void set(float r, float g, float b, float a);
	void set(int r, int g, int b, int a);

	float getR();
	float getG();
	float getB();
	float getA();

	int getRed();
	int getGreen();
	int getBlue();
	int getAlpha();

private:
	float r;
	float g;
	float b;
	float a;

	int clamp(float c);
};