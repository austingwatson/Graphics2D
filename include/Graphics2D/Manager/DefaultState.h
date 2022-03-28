#pragma once

#include <Graphics2D/State.h>

class DefaultState : public State
{
public:
	void init(GameContainer& gc);
	void enter(GameContainer& gc);
	void update(GameContainer& gc, float delta);
	void render(GameContainer& gc, Graphics& g);
	int getID();
};