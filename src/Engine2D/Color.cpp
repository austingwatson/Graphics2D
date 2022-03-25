#include <Engine2D/Color.h>

Color::Color()
{
	r = 0.0;
	g = 0.0;
	b = 0.0;
	a = 0.0;
}

Color::Color(float r, float g, float b, float a)
{
	this->r = clamp(r);
	this->g = clamp(g);
	this->b = clamp(b);
	this->a = clamp(a);
}

Color::Color(int r, int g, int b, int a)
{
	this->r = clamp(r / 255.0);
	this->g = clamp(g / 255.0);
	this->b = clamp(b / 255.0);
	this->a = clamp(a / 255.0);
}

void Color::set(float r, float g, float b, float a)
{
	this->r = clamp(r);
	this->g = clamp(g);
	this->b = clamp(b);
	this->a = clamp(a);
}

void Color::set(int r, int g, int b, int a)
{
	this->r = clamp(r / 255.0);
	this->g = clamp(g / 255.0);
	this->b = clamp(b / 255.0);
	this->a = clamp(a / 255.0);
}

int Color::clamp(float c)
{
	if (c < 0.0)
		c = 0.0;
	else if (c > 1.0)
		c = 1.0;

	return c;
}

float Color::getR()
{
	return r;
}

float Color::getG()
{
	return g;
}

float Color::getB()
{
	return b;
}

float Color::getA()
{
	return a;
}

int Color::getRed()
{
	return r * 255;
}

int Color::getGreen()
{
	return g * 255;
}

int Color::getBlue()
{
	return b * 255;
}

int Color::getAlpha()
{
	return a * 255;
}