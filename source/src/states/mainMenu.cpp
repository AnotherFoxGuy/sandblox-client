#include "globalVars.hpp"
#include "states/mainMenu.hpp"
#include <cstdio>

// This unused param HAS to be here for CEGUI's sake
bool mainMenu::onExitClicked( const CEGUI::EventArgs& e )
{
	// Use this line to suppress the unused variable warning.
	( void )( e );
	g_Client->getStateManager()->pushState( "mainGame" );
	return true;
}


/*
 * Function for drawing the main menu
 */
void mainMenu::draw()
{
	// Always remember to clear the window
	glClearColor( 0.0f, 0.5f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT );

	// Draw the GUI, duh
	m_gui.draw();
}

/*
 * Function for updating the main menu
 */
void mainMenu::update()
{
	// Update the GUI(s)
	m_gui.update();
}

/*
 * Function for handling the GameState's events
 */

void mainMenu::handleEvent( SDL_Event& event )
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

	// Pass the event into the GUI
	m_gui.onSDLEvent( event );
}

/*
 * This runs immeadiately after the GameStateManager changes states.
 */
void mainMenu::enter()
{
	// Testing GUIs -----------------------------------------------------------------
	m_gui = GUI();
	m_gui.init( "C:/Qub3d/Qub3d/sandblox-client/development_game/Dev_Game/GUI" );

	m_gui.loadScheme( "TaharezLook.scheme" );

	m_gui.setFont( "DejaVuSans-10" );

	CEGUI::PushButton* ExitButton = static_cast<CEGUI::PushButton*>( m_gui.createWidget(
										"TaharezLook/Button", glm::vec4( .475f, .45f, .1f, .05f ), glm::vec4( 0.0f ), "ExitButton" ) );

	ExitButton->setText( "Exit Game" );

	ExitButton->subscribeEvent( CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber( &mainMenu::onExitClicked, this ) );

	m_gui.setMouseCursor( "TaharezLook/MouseArrow" );
	m_gui.showMouseCursor();
	//--------------------------------------------------------------------------------
}

/*
 * This runs before the GameStateManager changes states.
 */
void mainMenu::exit()
{
	// Safety first!
	m_gui.destroy();
}
