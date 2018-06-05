#include "states/stateMap.hpp"
#include "states/playingScreen.hpp"
#include "states/mainScreen.hpp"
#include "states/optionsScreen.hpp"
#include "states/singlePlayerScreen.hpp"
#include "states/multiPlayerScreen.hpp"

stateMap::~stateMap()
{
	
}

void stateMap::initStateMap()
{
	// We insert a GameState object into the map for each state
	m_stateMap.insert( std::make_pair( "mainScreen", std::shared_ptr<GameState>(new mainScreen() ) ) );
	m_stateMap.insert( std::make_pair( "playingScreen", std::shared_ptr<GameState>(new playingScreen() ) ) );
	m_stateMap.insert( std::make_pair( "singlePlayerScreen", std::shared_ptr<GameState>(new singlePlayerScreen() ) ) );
	m_stateMap.insert( std::make_pair( "multiPlayerScreen", std::shared_ptr<GameState>(new multiPlayerScreen() ) ) );
	m_stateMap.insert( std::make_pair( "optionsScreen", std::shared_ptr<GameState>(new optionsScreen() ) ) );
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
