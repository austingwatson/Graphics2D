#pragma once

class Shader {
public:
	Shader();
	void init(const char* vertexPath, const char* fragmentPath);
	void destroy();
	void setUniformMatrix4fv(const char* name, float* value);
	void use();
	unsigned int getID();

private:
	unsigned int id;
};