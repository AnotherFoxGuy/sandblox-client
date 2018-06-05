#pragma once
#include "states/GameState.hpp"
#include "globalVars.hpp"
#include <GL/glew.h>

class playingScreen : public GameState
{
public:
	// Constructor and destructor
	playingScreen() {}
	~playingScreen() {}

	// More functions to come soon

	// Override functions from the parent GameState class
	void draw() override;
	void update() override;

	void handleEvent( SDL_Event& event ) override;

	// State switching helper functions
	void enter() override;
	void exit() override;

};
