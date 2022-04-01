#include <Graphics2D/Math/Mat4f.h>

Mat4f::Mat4f()
{
	elements = new float[4 * 4];
}

Mat4f::~Mat4f()
{
	delete elements;
}

void Mat4f::identity()
{
	for (int i = 0; i < 4 * 4; ++i)
		elements[i] = 0.0f;

	elements[0 + 0 * 4] = 1.0f;
	elements[1 + 1 * 4] = 1.0f;
	elements[2 + 2 * 4] = 1.0f;
	elements[3 + 3 * 4] = 1.0f;
}

void Mat4f::ortho(float left, float right, float bottom, float top, float near, float far)
{
	identity();

	elements[0 + 0 * 4] = 2.0f / (right - left);
	elements[1 + 1 * 4] = 2.0f / (top - bottom);
	elements[2 + 2 * 4] = 2.0f / (near - far);

	elements[0 + 3 * 4] = (left + right) / (left - right);
	elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
	elements[2 + 3 * 4] = (near + far) / (far - near);
}

void Mat4f::multiply(const Mat4f& mat4f)
{
	Mat4f result;

	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			float sum = 0.0f;
			for (int e = 0; e < 4; ++e)
			{
				sum += this->elements[e + y * 4] * mat4f.elements[x + e * 4];
			}
			result.elements[x + y * 4] = sum;
		}
	}

	for (int i = 0; i < 4 * 4; ++i)
		this->elements[i] = result.elements[i];
}

void Mat4f::translate(float x, float y, float z)
{
	elements[0 + 3 * 4] = x;
	elements[1 + 3 * 4] = y;
	elements[2 + 3 * 4] = z;
}

void Mat4f::rotate(float angle, float x, float y, float z)
{
	static const double PI = 3.14159265358979323846;

	double radian = angle * PI / 180.0;
	float cosine = (float)cos(radian);
	float sine = (float)sin(radian);
	float omc = 1.0f - cosine;

	elements[0 + 0 * 4] = x * omc + cosine;
	elements[1 + 0 * 4] = y * x * omc + z * sine;
	elements[2 + 0 * 4] = x * z * omc - y * sine;

	elements[0 + 1 * 4] = x * y * omc - z * sine;
	elements[1 + 1 * 4] = y * omc + cosine;
	elements[2 + 1 * 4] = y * z * omc + x * sine;

	elements[0 + 2 * 4] = x * z * omc + y * sine;
	elements[1 + 2 * 4] = y * z * omc - x * sine;
	elements[2 + 2 * 4] = z * omc + cosine;
}

void Mat4f::scale(float x, float y, float z)
{
	elements[0 + 3 * 4] *= x;
	elements[1 + 3 * 4] *= y;
	elements[2 + 3 * 4] *= z;
}

float* Mat4f::getElements()
{
	return elements;
}