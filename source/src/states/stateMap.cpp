#include "states/stateMap.hpp"
#include "states/mainGame.hpp"
#include "states/mainMenu.hpp"

stateMap::~stateMap()
{
	
}

void stateMap::initStateMap()
{
	// We insert a GameState object into the map for each state
	m_stateMap.insert( std::make_pair( "mainMenu", std::shared_ptr<GameState>(new mainMenu() ) ) );
	m_stateMap.insert( std::make_pair( "mainGame", std::shared_ptr<GameState>(new mainGame() ) ) );
}

std::map<std::string, std::shared_ptr<GameState> >* stateMap::getStateMap()
{
	return &m_stateMap;
}

// Returns a state by it's string handle for easier programming
std::shared_ptr<GameState> stateMap::getStateByName( const string_t& name )
{
	if( m_stateMap.find( name ) != m_stateMap.end() )
	{
		return m_stateMap[name];
	}

	// If the state is not here return a nullptr, error checking should be done when this is used.
	return nullptr;
}
