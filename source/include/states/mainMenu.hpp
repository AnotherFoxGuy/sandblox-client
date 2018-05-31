#pragma once
#include "states/GameState.hpp"
#include "gui/gui.hpp"
#include "CEGUI/CEGUI.h"
#include "CEGUI/RendererModules/OpenGL/GL3Renderer.h"


class mainMenu : public GameState
{
public:

	// Constructor and destructor
	mainMenu(){}
	~mainMenu()
	{
		// Safety first as they say!
		m_gui.destroy();
	}

	// Testing only, this will be removed later once things start coming together
	bool onExitClicked( const CEGUI::EventArgs& e );

	// Override functions from the GameState parent class
	// Game Runtime Functions
	void draw() override;
	void update() override;

	void handleEvent( SDL_Event& event ) override;
	// State switching helper functions
	void enter() override;
	void exit() override;

protected:
	GUI m_gui;

};
