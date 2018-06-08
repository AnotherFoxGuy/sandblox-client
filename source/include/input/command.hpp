#pragma once
#include "types.hpp"

// This allows us to handle different types of Commands differently
enum class CommandType
{
	NORMAL, NOTHING
};

// This Command class allows us to handle events differently in an object-oriented way
class Command
{
public:
	virtual ~Command(){};
	virtual void execute(SDL_Event& event) = 0;
	CommandType type()
	{
		return m_type;
	}
protected:
	CommandType m_type;
};
