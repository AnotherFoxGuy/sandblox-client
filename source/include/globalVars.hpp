#pragma once
#include <memory>
#include "SandBlox.hpp"

// This allows any part of the program to access all of the vars 
// in the Client class that we need such as the GameStateManager
extern std::unique_ptr<SandBlox> g_Client;
