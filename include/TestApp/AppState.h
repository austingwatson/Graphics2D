#pragma once

#include <Engine2D/GameContainer.h>

class State;
class Graphics;

class AppState : public State
{
public:
	void init(GameContainer& gc);
	void enter(GameContainer& gc);
	void leave(GameContainer& gc);
	void update(GameContainer& gc, float delta);
	void render(GameContainer& gc, Graphics& g);
	int getID();

private:

};