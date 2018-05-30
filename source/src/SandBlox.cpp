#include "SandBlox.hpp"
#include <cstdlib>

SandBlox::SandBlox()
{
	
}

SandBlox::~SandBlox()
{
	delete m_stateManager;
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

void SandBlox::setIsRunning(bool isRunning)
{
	m_isRunning = isRunning;
}

gameStateManager* SandBlox::getStateManager()
{
	return m_stateManager;
}

void SandBlox::initSystems()
{
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
		printf( "Could not create window: %s\n", SDL_GetError() );
		exit( EXIT_FAILURE );
	}
	
	SDL_GLContext glContext = SDL_GL_CreateContext(m_mainWindow);
	if(glContext==nullptr)
	{
		printf( "Could not create openGL context: %s\n", SDL_GetError() );
	}
	
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		// Problem: glewInit failed, something is seriously wrong.
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	// Print out openGL version for confirmation
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	
	glewExperimental = GL_TRUE;
	
	//----------------member variables------------------
	
	m_stateManager = new gameStateManager();
	
	m_stateManager->init();

	printf("Systems Initialized\n");
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
