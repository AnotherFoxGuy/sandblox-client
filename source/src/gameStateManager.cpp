#include "gameStateManager.hpp"

/*
 * Class constructor
 */
gameStateManager::gameStateManager()
{
	m_stateMap = std::shared_ptr<stateMap>( new stateMap() );
}

/*
 * Class destructor
 */
gameStateManager::~gameStateManager()
{

}

void gameStateManager::init( const string_t& name )
{

	// Initialize the gamestates for SandBlox
	m_stateMap->initStateMap();
	// Push the main menu onto the stack
	m_stateStack.push_back( m_stateMap->getStateByName( name ) );
	// Run the entry code
	m_stateStack.back()->enter();
}

std::shared_ptr<stateMap> gameStateManager::getStateMap()
{
	return m_stateMap;
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
void gameStateManager::handleEvent( SDL_Event& event )
{
	m_stateStack.back()->handleEvent( event );
}

//-------------------------------------------------------//
//                    Stack Functions                    //
//-------------------------------------------------------//

/*
 * Push a state onto the front of the stack
 */
void gameStateManager::pushState( const string_t& newState )
{
	// Run the old GameState's exit code before switching.
	m_stateStack.back()->exit();

	// Push a new GameState onto the stack
	m_stateStack.push_back( m_stateMap->getStateByName( newState ) );

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
void gameStateManager::setCurrentState( const string_t& newState )
{
	// Run the old GameState's exit code before switching.
	m_stateStack.back()->exit();

	// Set the new GameState directly
	m_stateStack.back() = m_stateMap->getStateByName( newState );

	// Run the new GameState's entry code.
	m_stateStack.back()->enter();

}
