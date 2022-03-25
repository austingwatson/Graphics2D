#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Engine2D/Manager/StateManager.h>
#include <Engine2D/Graphics/Graphics.h>

class GameContainer
{
public:
	GameContainer();
	~GameContainer();

	bool setWindowed(int width, int height);
	bool setFullscreen(int width, int height);
	bool setBorderlessFullscreen();
	void start();
	void exit();

	void addState(State& state);
	void enterState(int id);

private:
	GLFWwindow* window;
	int width;
	int height;

	StateManager* stateManager;
	Graphics* graphics;
};