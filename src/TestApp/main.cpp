#include <Graphics2D/GameContainer.h>
#include <TestApp/AppState.h>

int main()
{
	GameContainer gc;
	if (gc.setWindowed(1280, 720))
	{
		AppState appState;
		gc.addState(appState);

		gc.start();
	}

	return 0;
}