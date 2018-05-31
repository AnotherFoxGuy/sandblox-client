#include "states/mainGame.hpp"
#include "globalVars.hpp"

/*
 * Function for drawing the GameState
 */
void mainGame::draw()
{
	// Always remember to clear the window
	glClearColor( 0.0f, 0.0f, 0.5f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

/*
 * Function for updating the GameState
 */
void mainGame::update()
{

}

/*
 * Function for handling the GameState's events
 */
void mainGame::handleEvent( SDL_Event& event )
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
 * This runs immeadiately after the GameStateManager changes states.
 */
void mainGame::enter()
{

}

/*
 * This runs before the GameStateManager changes states.
 */
void mainGame::exit()
{

}
