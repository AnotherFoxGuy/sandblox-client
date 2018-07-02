#pragma once
#include <map>
#include <string>
#include <memory>
#include "types.hpp"
#include "states/GameState.hpp"

class stateMap
{
public:
	stateMap() {}
	~stateMap() {};

	void initStateMap();

	std::map< string_t, std::shared_ptr<GameState> >* getStateMap();

	std::shared_ptr<GameState> getStateByName( const string_t& name );

protected:
	std::map< string_t, std::shared_ptr<GameState> > m_stateMap;
};
