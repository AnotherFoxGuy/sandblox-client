#pragma once
#include <vector>
#include <memory>
#include "states/GameState.hpp"
#include "states/mainMenu.hpp"
#include "states/mainGame.hpp"

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

	void init();

	//-------------------------------------------------------//
	//                 Game Runtime Functions                //
	//-------------------------------------------------------//

	// This calls the current GameState's drawing function.
	void draw();

	// This calls the current GameState's update function.
	void update();

	void handleEvent(SDL_Event &event);

	// These functions are for handling the GameState stack.

	// For pushing a state onto the top of the stack.
	void pushState(GameState *newState);
	// For pulling one off of the stack.
	void popState();

	// For setting the current state I.E. "MAINMENU->(pushes)LOADING->(sets)PLAYING",
	// so this can happen "PLAYING->(pop)MAINMENU"
	void setCurrentState(GameState *newState);

	// Getters for the GameStates so it is easy to access them.
	mainMenu* getMainMenu();
	mainGame* getMainGame();


protected:
	// These are the GameStates that are available for switching.
	std::unique_ptr< mainMenu > m_mainMenu;
	std::unique_ptr< mainGame > m_mainGame;


private:
	// The stack of GameStates for easy transition handling
	std::vector< GameState* > m_stateStack;
};
