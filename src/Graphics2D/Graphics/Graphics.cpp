#include <Graphics2D/Graphics/Graphics.h>

Graphics::Graphics()
{
	rectShader = nullptr;
	buffer = nullptr;
	color = new Color();
}

Graphics::~Graphics()
{
	delete rectShader;
	delete buffer;
	delete color;
}

void Graphics::init()
{
	rectShader = new Shader();
	rectShader->init("C:\\zCode\\c++\\Graphics2D\\shaders\\rectangle.vs", "C:\\zCode\\c++\\Graphics2D\\shaders\\rectangle.fs");

	float vertices[] = {
		// positions          // colors           
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f  // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	buffer = new Buffer();
	buffer->init(vertices, 24, indices, 6);
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
	rectShader->use();
	buffer->use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}