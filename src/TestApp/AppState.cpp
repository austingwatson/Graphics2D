#include <TestApp/AppState.h>

#include <iostream>

void AppState::init(GameContainer& gc)
{

}

void AppState::enter(GameContainer& gc)
{

}

void AppState::leave(GameContainer& gc)
{

}

void AppState::update(GameContainer& gc, float delta)
{

}

void AppState::render(GameContainer& gc, Graphics& g)
{
	g.drawRect(500.0, 500.0, 50.0, 50.0);
}

int AppState::getID()
{
	return 0;
}
