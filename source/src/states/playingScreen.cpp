#include <GL/glew.h>
#include "states/playingScreen.hpp"

void playingScreen::shouldCloseWindow( SDL_Event& event )
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
 * Function for drawing the GameState
 */
void playingScreen::draw( )
{
	// Always remember to clear the window
	glClearColor( 0.0f, 0.0f, 0.5f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

/*
 * Function for updating the GameState
 */
void playingScreen::update( )
{

}

/*
 * Function for handling the GameState's events
 */
void playingScreen::handleEvent( SDL_Event& event )
{
	switch ( m_playingState )
	{
		case playingState::PLAYING:
			shouldCloseWindow( event );
			break;
		case playingState::PAUSED:
			shouldCloseWindow( event );
			break;
		case playingState::CHATTING:
			shouldCloseWindow( event );
			break;
		case playingState::SHOW_GUI:
			shouldCloseWindow( event );
			break;
	}
	std::shared_ptr<Command> inputCommand = m_inputHandler->handleInput(event);
	// if the command is null, that means nothing happened or something happened that was not handled.
	if (inputCommand != nullptr)
	{
		inputCommand->execute(event);
	}
}

/*
 * This runs immediately after the GameStateManager changes states.
 */
void playingScreen::enter( )
{
	m_inputHandler->initCommandMap();
	m_inputHandler->initInputCommands();
}

/*
 * This runs before the GameStateManager changes states.
 */
void playingScreen::exit( )
{
	
}
