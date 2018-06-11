#include "globalVars.hpp"
#include "states/mainScreen.hpp"
#include <cstdio>

/*
 * Function for drawing the main menu
 */
void mainScreen::draw()
{
	// Always remember to clear the window
	glClearColor( 0.0f, 0.5f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

/*
 * Function for updating the main menu
 */
void mainScreen::update()
{
}

/*
 * Function for handling the GameState's events
 */

void mainScreen::handleEvent( SDL_Event& event )
{
	if ( event.type == SDL_WINDOWEVENT )
	{
		switch ( event.window.event )
		{
			case SDL_WINDOWEVENT_CLOSE:
				// Yes the window should close.
				g_Client->setIsRunning( false );
				break;
		}
	}
}

/*
 * This runs immediately after the GameStateManager changes states.
 */
void mainScreen::enter()
{
}

/*
 * This runs before the GameStateManager changes states.
 */
void mainScreen::exit()
{
}
