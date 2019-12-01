
#include "Display.hpp"
#include "Manager.hpp"

int     main(int ac, char **av)
{
	IDisplay		*window = new Display;
        Manager			*GameManager = new Manager(window);
	window->createWindow();
        GameManager->initManager();
        GameManager->startManager();

	delete window;
	return 0;
}