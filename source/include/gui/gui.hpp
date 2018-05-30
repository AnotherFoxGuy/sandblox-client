#pragma once

#include <GL/glew.h>
#include <glm/vec4.hpp>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>
#include <SDL_events.h>

class GUI
{
public:
	// Initialization requires a resourceDirectory to be able to load the schemes, fonts, etc.
	void init( const std::string& resourceDirectory );
	void destroy();

	// Drawing and Updating
	void draw();
	void update();

	// Mouse image overrides
	void setMouseCursor( const std::string& imageFile );
	void showMouseCursor();
	void hideMouseCursor();

	// Event handling
	void onSDLEvent( SDL_Event& event );

	void loadScheme( const std::string& schemeFile );
	void setFont( const std::string& fontFile );

	/* This adds a widget to m_rootWindow
	 * Examples of parameters and explanations
	 * type: "TaharezLook/Button" This specifies the type of widget being created.
	 * destRectPercent: glm::vec4(Posx, Posy, Height, Width) NOTE: These are percentages!
	 * destRectPixel: glm::vec4(Posx, Posy, Height, Width) NOTE: These are actual pixels!
	 * name: This is the name of the component, it would be usefull to make this consistent
	 * with the variable name you use to store the widget in, if you so choose to do so.
	 */
	CEGUI::Window* createWidget( const std::string& type, const glm::vec4& destRectPercent, const glm::vec4& destRectPixel, const std::string& name = "" );

	// This sets the widget dims according to destRectPercent and destRectPixel
	static void setWidgetDims( CEGUI::Window* widget, const glm::vec4& destRectPercent, const glm::vec4& destRectPixel );

	// Getters
	static CEGUI::OpenGL3Renderer* getRenderer()
	{
		return m_GUIRenderer;

	};
	const CEGUI::GUIContext* getContext()
	{
		return m_GUIContext;
	};

private:
	static CEGUI::OpenGL3Renderer* m_GUIRenderer;
	CEGUI::GUIContext* m_GUIContext = nullptr;
	CEGUI::Window* m_rootWindow = nullptr;
	// This is for anything that might need the the time(GUI animations mostly), it's used in GUI::update()
	unsigned int m_lastTime = 0;
};
