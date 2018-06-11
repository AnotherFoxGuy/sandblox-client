#pragma once
#include "states/playingScreenStates.hpp"
#include "states/GameState.hpp"
#include "input/inputHandler.hpp"
#include "globalVars.hpp"

class playingScreen : public GameState
{
public:
	// Constructor and destructor
	playingScreen() 
	: m_inputHandler(std::unique_ptr<inputHandler>(new inputHandler()))
	{
		
	}
	~playingScreen() {}

	void shouldCloseWindow(SDL_Event& event);

	// Override functions from the parent GameState class
	void draw() override;
	void update() override;

	void handleEvent( SDL_Event& event ) override;

	// State switching helper functions
	void enter() override;
	void exit() override;
	
protected:
	std::unique_ptr<inputHandler> m_inputHandler;

protected:
	playingState m_playingState = playingState::PLAYING;
};
