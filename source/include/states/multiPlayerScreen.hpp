#pragma once
#include "states/GameState.hpp"
#include "globalVars.hpp"
#include <GL/glew.h>

class multiPlayerScreen : public GameState
{
public:
	// Constructor and destructor
	multiPlayerScreen() {}
	~multiPlayerScreen() {}

	// More functions to come soon

	// Override functions from the parent GameState class
	void draw() override;
	void update() override;

	void handleEvent( SDL_Event& event ) override;

	// State switching helper functions
	void enter() override;
	void exit() override;
};
