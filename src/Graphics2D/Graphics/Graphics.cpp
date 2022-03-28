#include <Graphics2D/Graphics/Graphics.h>

Graphics::Graphics()
{
	rectShader = nullptr;
	buffer = nullptr;
	color = new Color();
}

Graphics::~Graphics()
{
	rectShader->destroy();
	delete rectShader;
	delete buffer;
	delete color;
}

void Graphics::create()
{
	rectShader = new Shader();
	rectShader->create("C:\\zCode\\c++\\Engine2D\\shaders\\rectangle.vs", "C:\\zCode\\c++\\Engine2D\\shaders\\rectangle.fs");

	float vertices[] = {
		// positions         // colors
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};

	buffer = new Buffer();
	buffer->create(vertices, 18);
}

void Graphics::destroy()
{
	rectShader->destroy();
	buffer->destroy();
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
	glClear(GL_COLOR_BUFFER_BIT);
}

void Graphics::drawRect(float x, float y, float width, float height)
{

}

void Graphics::fillRect(float x, float y, float width, float height)
{

}