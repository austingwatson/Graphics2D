#pragma once

#include <glad/glad.h>

#include <Engine2D/Color.h>

class Graphics {
public:
	Graphics();
	~Graphics();
	void setColor(float r, float g, float b, float a);
	void setColor(int r, int g, int b, int a);
	void clear();

	void drawRect(float x, float y, float width, float height);
	void fillRect(float x, float y, float height, float width);

private:
	Color* color;
};