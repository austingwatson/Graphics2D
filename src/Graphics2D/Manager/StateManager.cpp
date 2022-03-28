#include <Graphics2D/Manager/StateManager.h>

StateManager::StateManager()
{
	currentState = -1;
	gc = nullptr;
	defaultState = nullptr;
}

StateManager::~StateManager()
{
	states.at(currentState)->leave(*gc);
	gc = nullptr;
	delete defaultState;
	defaultState = nullptr;
}

void StateManager::addState(State* state)
{
	states.push_back(state);
	if (currentState == -1)
		currentState = state->getID();
}

void StateManager::enterState(int id)
{
	states.at(currentState)->leave(*gc);
	currentState = id;
	states.at(currentState)->enter(*gc);
}

void StateManager::initAll(GameContainer* gc)
{
	if (states.empty())
	{
		defaultState = new DefaultState();
		addState(defaultState);
	}

	this->gc = gc;

	for (auto& element : states)
	{
		element->init(*gc);
	}

	states.at(currentState)->enter(*gc);
}

void StateManager::update(float delta)
{
	states.at(currentState)->update(*gc, delta);
}

void StateManager::render(Graphics& g)
{
	states.at(currentState)->render(*gc, g);
}
