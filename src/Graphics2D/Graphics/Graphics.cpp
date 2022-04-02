#include <Graphics2D/Graphics/Graphics.h>

#include <Graphics2D/Math/Mat4f.h>
#include <iostream>

Graphics::Graphics()
{
	rectShader = new Shader();
	buffer = new Buffer();
	color = new Color();

	model = new Mat4f();
	view = new Mat4f();
	projection = new Mat4f();
}

Graphics::~Graphics()
{
	delete rectShader;
	delete buffer;
	delete color;

	delete model;
	delete view;
	delete projection;
}

void Graphics::init(float width, float height)
{
	rectShader->init("C:\\zCode\\c++\\Graphics2D\\shaders\\rectangle.vs", "C:\\zCode\\c++\\Graphics2D\\shaders\\rectangle.fs");

	float vertices[] = {
		// positions                   
		 0.5f,  0.5f, 0.0f, // top right
		 0.5f, -0.5f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f  // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	buffer->init(vertices, 12, indices, 6);
	buffer->setAttributef(0, 3, 3, 0); // position

	projection->ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
	view->identity();
	model->identity();

	rectShader->setUniformMatrix4fv("view", view->getElements());
	rectShader->setUniformMatrix4fv("projection", projection->getElements());
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
	model->translate(50.0f, 50.0f, 0.0f);
	model->scale(width, height, 1.0f);

	rectShader->setUniform4f("color", color->getR(), color->getG(), color->getB(), color->getA());
	rectShader->setUniformMatrix4fv("model", model->getElements());
	buffer->use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	model->identity();
}