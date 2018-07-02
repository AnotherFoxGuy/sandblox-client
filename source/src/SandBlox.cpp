#include "SandBlox.hpp"
#include <cstdlib>
#include <SDL2/SDL.h>

SandBlox::SandBlox()
{
	
}

SandBlox::~SandBlox()
{
	
}

void SandBlox::run()
{
	initSystems();
	mainGameLoop();
	quitGame();
}

bool SandBlox::isRunning()
{
	return m_isRunning;
}

void SandBlox::setIsRunning( bool isRunning )
{
	m_isRunning = isRunning;
}

std::shared_ptr<gameStateManager> SandBlox::getStateManager()
{
	return m_stateManager;
}

void SandBlox::initSystems()
{
	// Using namespace pawlib for cleaner code.
	using namespace pawlib;
	using namespace pawlib::ioformat;
	
	//-----------------SDL and openGL-------------------

	SDL_Init( SDL_INIT_EVERYTHING );

	m_mainWindow = SDL_CreateWindow(
					   "Qub3d",
					   SDL_WINDOWPOS_CENTERED,
					   SDL_WINDOWPOS_CENTERED,
					   800, 600,
					   SDL_WINDOW_OPENGL );

	if( m_mainWindow == NULL )
	{
		// In the case that the window could not be made...
		ioc << cat_error << fg_red << "Could not create window: " << SDL_GetError() << io_end;
		exit( EXIT_FAILURE );
	}

	SDL_GLContext glContext = SDL_GL_CreateContext( m_mainWindow );

	if( glContext == nullptr )
	{
		ioc << cat_error << fg_red << "Could not create openGL context: " << SDL_GetError() << io_end;
	}

	GLenum err = glewInit();

	if( GLEW_OK != err )
	{
		// Problem: glewInit failed, something is seriously wrong.

		ioc << cat_error << fg_red << "Error: " << glewGetErrorString( err ) << io_end;
	}

	// Print out openGL version for confirmation
	ioc << fg_blue << "Status: Using GLEW " << glewGetString( GLEW_VERSION ) << io_end;

	glewExperimental = true;

	//----------------member variables------------------


	m_stateManager = std::shared_ptr<gameStateManager>( new gameStateManager() ) ;

	m_stateManager->init( "mainScreen" );

	ioc << fg_blue << "Systems Initialized" << io_end;
}

void SandBlox::mainGameLoop()
{
	m_isRunning = true;

	while( m_isRunning )
	{
		// Handle all the events
		SDL_Event event;
		while( SDL_PollEvent( &event ) )
		{
			m_stateManager->handleEvent(event);
		}
		
		m_stateManager->draw();
		m_stateManager->update();
		
		SDL_GL_SwapWindow(m_mainWindow);

	}
}

void SandBlox::quitGame()
{
	SDL_DestroyWindow( m_mainWindow );
	SDL_Quit();
}
