#include "gameStateManager.hpp"

/*
 * Class constructor
 */
gameStateManager::gameStateManager()
{
	// Initialize the gamestates for Qub3d
	m_mainMenu = std::unique_ptr<mainMenu>(new mainMenu());
	m_mainGame = std::unique_ptr<mainGame>(new mainGame());
}

/*
 * Class destructor
 */
gameStateManager::~gameStateManager()
{

}

void gameStateManager::init()
{
	// Push the main menu onto the stack
	m_stateStack.push_back(m_mainMenu.get());
	// Run the entry code
	m_stateStack.back()->enter();
}


//-------------------------------------------------------//
//                 Game Runtime Functions                //
//-------------------------------------------------------//

/*
 * Function for calling the current state's drawing function
 */
void gameStateManager::draw()
{
	m_stateStack.back()->draw();
}

/*
 * Function for calling the current state's update function
 */
void gameStateManager::update()
{
	m_stateStack.back()->update();
}

/*
 * Function for handling the current state's events
 */
void gameStateManager::handleEvent(SDL_Event &event)
{
	m_stateStack.back()->handleEvent(event);
}

//-------------------------------------------------------//
//                    Stack Functions                    //
//-------------------------------------------------------//

/*
 * Push a state onto the front of the stack
 */
void gameStateManager::pushState(GameState *newState)
{
	// Run the old GameState's exit code before switching.
	m_stateStack.back()->exit();

	// Push a new GameState onto the stack
	m_stateStack.push_back(newState);

	// Run the new GameState's entry code.
	m_stateStack.back()->enter();
}

/*
 * Pull a state off of the stack
 */
void gameStateManager::popState()
{
	// Run the old GameState's exit code before switching.
	m_stateStack.back()->exit();

	// Pop the current GameState off the stack.
	m_stateStack.pop_back();

	// Run the new GameState's entry code.
	m_stateStack.back()->enter();
}

/*
 * Set the current state directly
 */
void gameStateManager::setCurrentState(GameState* newState)
{
	// Run the old GameState's exit code before switching.
	m_stateStack.back()->exit();

	// Set the new GameState directly
	m_stateStack.back() = newState;

	// Run the new GameState's entry code.
	m_stateStack.back()->enter();

}

//-------------------------------------------------------//
//                     State Getters                     //
//-------------------------------------------------------//

mainMenu* gameStateManager::getMainMenu()
{
	// Get the pointer via std::uniqur_ptr's get() method
	return m_mainMenu.get();
}

mainGame* gameStateManager::getMainGame()
{
	// Get the pointer via std::uniqur_ptr's get() method
	return m_mainGame.get();
}
