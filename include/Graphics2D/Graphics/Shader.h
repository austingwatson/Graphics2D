#pragma once

class Shader {
public:
	Shader();
	void init(const char* vertexPath, const char* fragmentPath);
	void destroy();
	void use();

private:
	unsigned int id;
};