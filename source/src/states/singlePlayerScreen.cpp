#include "states/singlePlayerScreen.hpp"

/*
 * Function for drawing the GameState
 */
void singlePlayerScreen::draw()
{
	// Always remember to clear the window
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

/*
 * Function for updating the GameState
 */
void singlePlayerScreen::update()
{
	
}

/*
 * Function for handling the GameState's events
 */
void singlePlayerScreen::handleEvent( SDL_Event& event )
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
void singlePlayerScreen::enter()
{

}

/*
 * This runs before the GameStateManager changes states.
 */
void singlePlayerScreen::exit()
{

}
