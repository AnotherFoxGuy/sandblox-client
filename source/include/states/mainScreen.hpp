#pragma once
#include "states/GameState.hpp"


class mainScreen : public GameState
{
public:

	// Constructor and destructor
	mainScreen(){}
	~mainScreen()
	{
        }

	// Override functions from the GameState parent class
	// Game Runtime Functions
	void draw() override;
	void update() override;

	void handleEvent( SDL_Event& event ) override;
	// State switching helper functions
	void enter() override;
	void exit() override;

protected:

};
