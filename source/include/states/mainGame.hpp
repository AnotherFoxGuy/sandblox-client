#pragma once
#include "states/GameState.hpp"

class mainGame : public GameState
{
public:
	// Constructor and destructor
	mainGame() {}
	~mainGame() {}

	// More functions to come soon

	// Override functions from the parent GameState class
	void draw() override;
	void update() override;

	void handleEvent( SDL_Event& event ) override;

	// State switching helper functions
	void enter() override;
	void exit() override;

};
