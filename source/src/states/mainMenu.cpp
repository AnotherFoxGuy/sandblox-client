#include "states/mainMenu.hpp"
#include "globalVars.hpp"

/*
 * Function for drawing the main menu
 */
void mainMenu::draw()
{
	
}

/*
 * Function for updating the main menu
 */
void mainMenu::update()
{
	
}

/*
 * Function for handling the GameState's events
 */
void mainMenu::handleEvent(SDL_Event *event)
{
	if( event->type == SDL_WINDOWEVENT )
	{
		switch( event->window.event )
		{
			case SDL_WINDOWEVENT_CLOSE:
				// Yes the window should close.
				g_Client->setIsRunning(false);
				break;
		}
	}
}

/*
 * This runs immeadiately after the GameStateManager changes states.
 */
void mainMenu::enter()
{
	
}

/*
 * This runs before the GameStateManager changes states.
 */
void mainMenu::exit()
{

}
