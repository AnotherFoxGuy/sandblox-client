#pragma once

#include <SDL2/SDL.h>

/*
 * This is the base class for all GameStates.
 * Each GameState MUST include each of these functions.
 */
class GameState
{
public:
	virtual ~GameState(){}
	// Game runtime functions

	// Draw function called by GameStateManager::draw()
	virtual void draw() = 0;
	// Update function called by GameStateManager::update()
	virtual void update() = 0;
	// Function to handle SDL events
	virtual void handleEvent( SDL_Event& event ) = 0;
	// Function called upon a state being pushed or set by GameStateManager.
	virtual void enter() = 0;
	// Function called upon a state exiting the stack or being pushed down into the stack.
	virtual void exit() = 0;

};
