#pragma once

#include <glad/glad.h>

class Buffer
{
public:
	Buffer();
	void create(float* vertices, unsigned int verticesSize);
	void create(float* vertices, unsigned int verticesSize, unsigned int* indices, unsigned int indicesSize);
	void destroy();
	void use();

private:
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
};