#pragma once

#include <vector>

#include <Engine2D/State.h>
#include <Engine2D/Manager/DefaultState.h>

class GameContainer;
class Graphics;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void addState(State* state);
	void enterState(int id);
	void initAll(GameContainer* gc);
	void update(float delta);
	void render(Graphics& g);

private:
	int currentState;
	std::vector<State*> states;
	GameContainer* gc;
	DefaultState* defaultState;
};