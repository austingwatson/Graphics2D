#pragma once

#include <glad/glad.h>
#include <stb_image/stb_image.h>

class Texture {
public:
	Texture();
	void init(const char* path);
	void destroy();
	void use();

private:
	unsigned int id;
};