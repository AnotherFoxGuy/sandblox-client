#pragma once

// This tells the compiler to not use SDL's main function
#define SDL_MAIN_HANDLED

// This tells GLEW that it's using a static lib
#define GLEW_STATIC

#include <memory>
#include <cstdio>

#include "SDL.h"
#include "gameStateManager.hpp"

class SandBlox
{
public:
	SandBlox();
	~SandBlox();
	
	void run();
	
	bool isRunning();
	void setIsRunning(bool isRunning);
	
	gameStateManager* getStateManager();
	
private:
	
	void initSystems();
	void mainGameLoop();
	void quitGame();
	
protected:
	bool m_isRunning = false;
	gameStateManager *m_stateManager;
	SDL_Window *m_mainWindow = nullptr;
	
};
