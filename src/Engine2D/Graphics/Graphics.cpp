#include <Engine2D/Graphics/Graphics.h>

Graphics::Graphics()
{
	color = new Color();
}

Graphics::~Graphics()
{
	delete color;
}

void Graphics::setColor(float r, float g, float b, float a)
{
	color->set(r, g, b, a);
}

void Graphics::setColor(int r, int g, int b, int a)
{
	color->set(r, g, b, a);
}

void Graphics::clear()
{
	glClearColor(color->getR(), color->getG(), color->getB(), color->getA());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::drawRect(float x, float y, float width, float height)
{

}

void Graphics::fillRect(float x, float y, float width, float height)
{

}