#pragma once
#include <vector>
#include <memory>
#include "states/GameState.hpp"
#include "states/stateMap.hpp"
/*
* This class allows for easy management of
* the different states that the game might
* such as the main menus
*/
class gameStateManager
{
public:

	gameStateManager();
	~gameStateManager();

	void init( const string_t& name );
	
	std::shared_ptr<stateMap> getStateMap();

	//-------------------------------------------------------//
	//                 Game Runtime Functions                //
	//-------------------------------------------------------//

	// This calls the current GameState's drawing function.
	void draw();

	// This calls the current GameState's update function.
	void update();

	void handleEvent( SDL_Event& event );

	// These functions are for handling the GameState stack.

	// For pushing a state onto the top of the stack.
	void pushState( const string_t& newState );
	// For pulling one off of the stack.
	void popState();

	// For setting the current state I.E. "MAINMENU->(pushes)LOADING->(sets)PLAYING",
	// so this can happen "PLAYING->(pop)MAINMENU"
	void setCurrentState( const string_t& newState );


protected:
	std::shared_ptr< stateMap > m_stateMap;


private:
	// The stack of GameStates for easy transition handling
	std::vector< std::shared_ptr<GameState> > m_stateStack;
};
