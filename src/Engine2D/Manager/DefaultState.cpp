#include <Engine2D/Manager/DefaultState.h>

#include <iostream>

void DefaultState::init(GameContainer& gc)
{

}

void DefaultState::enter(GameContainer& gc)
{
	std::cout << "Please create derived class of State." << std::endl;
}

void DefaultState::update(GameContainer& gc, float delta)
{

}

void DefaultState::render(GameContainer& gc, Graphics& g)
{

}

int DefaultState::getID()
{
	return 0;
}