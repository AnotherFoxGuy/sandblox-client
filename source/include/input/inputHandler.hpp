#pragma once
#include <map>
#include <memory>
#include <SDL_events.h>
#include "input/command.hpp"

class inputHandler
{
public:
	inputHandler(){};
	~inputHandler(){};
	
	void initInputCommands();
	
	void initCommandMap();
	
	std::shared_ptr<Command> handleInput(SDL_Event& event);
	std::shared_ptr<Command> handleKeys(SDL_Event& event);
	std::shared_ptr<Command> handleMouse(SDL_Event& event);
private:
	void setCommand(const string_t& name, std::shared_ptr<Command> command);
	void insertCommandIntoMap(const string_t& name, std::shared_ptr<Command>& command);
	// This allows us to set commands by using a string 
	std::map<string_t, std::shared_ptr<Command>> m_commandMap;
};

