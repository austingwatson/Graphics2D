#pragma once

#include <math.h>

class Mat4f {
public:
	Mat4f();
	~Mat4f();
	void identity();
	void ortho(float left, float right, float bottom, float top, float near, float far);
	void multiply(const Mat4f& mat4f);
	void translate(float x, float y, float z);
	void rotate(float angle, float x, float y, float z);
	void scale(float x, float y, float z);
	float* getElements();

private:
	float* elements;
};