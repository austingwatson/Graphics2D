#pragma once

class Shader {
public:
	Shader();
	void init(const char* vertexPath, const char* fragmentPath);
	void destroy();
	void setUniform4f(const char* name, float v1, float v2, float v3, float v4);
	void setUniformMatrix4fv(const char* name, float* value);
	void use();
	unsigned int getID();

private:
	unsigned int id;
};