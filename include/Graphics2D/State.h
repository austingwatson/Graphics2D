#pragma once

class GameContainer;
class Graphics;

class State {
public:
	virtual void init(GameContainer& gc) = 0;
	virtual void update(GameContainer& gc, float delta) = 0;
	virtual void render(GameContainer& gc, Graphics& g) = 0;
	virtual int getID() = 0;

	virtual void enter(GameContainer& gc);
	virtual void leave(GameContainer& gc);
};