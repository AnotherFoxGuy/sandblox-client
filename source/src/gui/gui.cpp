#include "gui/gui.hpp"
#include <SDL_timer.h>

CEGUI::OpenGL3Renderer* GUI::m_GUIRenderer = nullptr;

void GUI::init( const std::string& resourceDirectory )
{
	// Check to see if the GUI is already initialized
	if ( m_GUIRenderer == nullptr )
	{
		m_GUIRenderer = &CEGUI::OpenGL3Renderer::bootstrapSystem();

		// This is the ResourceProvider which allows us to customize our GUI
		CEGUI::DefaultResourceProvider* rp =  static_cast<CEGUI::DefaultResourceProvider*>( CEGUI::System::getSingleton().getResourceProvider() );

		// Set the individual resource directories
		rp->setResourceGroupDirectory( "imagesets", resourceDirectory + "/imagesets/" );
		rp->setResourceGroupDirectory( "schemes", resourceDirectory + "/schemes/" );
		rp->setResourceGroupDirectory( "fonts", resourceDirectory + "/fonts/" );
		rp->setResourceGroupDirectory( "layouts", resourceDirectory + "/layouts/" );
		rp->setResourceGroupDirectory( "lua_scripts", resourceDirectory + "/lua_scripts/" );
		rp->setResourceGroupDirectory( "looknfeel", resourceDirectory + "/looknfeel/" );

		CEGUI::ImageManager::setImagesetDefaultResourceGroup( "imagesets" );
		CEGUI::Scheme::setDefaultResourceGroup( "schemes" );
		CEGUI::Font::setDefaultResourceGroup( "fonts" );
		CEGUI::WidgetLookManager::setDefaultResourceGroup( "looknfeel" );
		CEGUI::WindowManager::setDefaultResourceGroup( "layouts" );
		CEGUI::ScriptModule::setDefaultResourceGroup( "lua_scripts" );
	}

	m_GUIContext = &CEGUI::System::getSingleton().createGUIContext( m_GUIRenderer->getDefaultRenderTarget() );

	m_rootWindow = CEGUI::WindowManager::getSingleton().createWindow( "DefaultWindow", "root" );

	m_GUIContext->setRootWindow( m_rootWindow );
}

void GUI::destroy()
{
	// Destroy the GUI Context for memory safety
	CEGUI::System::getSingleton().destroyGUIContext( *m_GUIContext );
}

void GUI::draw()
{
	m_GUIRenderer->beginRendering();
	m_GUIContext->draw();
	m_GUIRenderer->endRendering();
	glDisable( GL_SCISSOR_TEST );
}

void GUI::update()
{
	unsigned int elapsed = 0;

	if ( m_lastTime == 0 )
	{
		m_lastTime = SDL_GetTicks();
	}
	else
	{
		unsigned int nextTime = SDL_GetTicks();
		elapsed = nextTime - m_lastTime;
		m_lastTime = nextTime;
	}

	m_GUIContext->injectTimePulse( ( float )( elapsed ) / 1000.0f );
}

void GUI::setMouseCursor( const std::string& imageFile )
{
	m_GUIContext->getMouseCursor().setDefaultImage( imageFile );
}

void GUI::showMouseCursor()
{
	m_GUIContext->getMouseCursor().show();
}

void GUI::hideMouseCursor()
{
	m_GUIContext->getMouseCursor().hide();
}

/************************************************************************
			Translate a SDL_Keycode to the proper CEGUI::Key
*************************************************************************/
CEGUI::Key::Scan SDLKeyToCEGUIKey( SDL_Keycode key )
{
	using namespace CEGUI;

	switch ( key )
	{
		case SDLK_BACKSPACE:
			return Key::Backspace;

		case SDLK_TAB:
			return Key::Tab;

		case SDLK_RETURN:
			return Key::Return;

		case SDLK_PAUSE:
			return Key::Pause;

		case SDLK_ESCAPE:
			return Key::Escape;

		case SDLK_SPACE:
			return Key::Space;

		case SDLK_COMMA:
			return Key::Comma;

		case SDLK_MINUS:
			return Key::Minus;

		case SDLK_PERIOD:
			return Key::Period;

		case SDLK_SLASH:
			return Key::Slash;

		case SDLK_0:
			return Key::Zero;

		case SDLK_1:
			return Key::One;

		case SDLK_2:
			return Key::Two;

		case SDLK_3:
			return Key::Three;

		case SDLK_4:
			return Key::Four;

		case SDLK_5:
			return Key::Five;

		case SDLK_6:
			return Key::Six;

		case SDLK_7:
			return Key::Seven;

		case SDLK_8:
			return Key::Eight;

		case SDLK_9:
			return Key::Nine;

		case SDLK_COLON:
			return Key::Colon;

		case SDLK_SEMICOLON:
			return Key::Semicolon;

		case SDLK_EQUALS:
			return Key::Equals;

		case SDLK_LEFTBRACKET:
			return Key::LeftBracket;

		case SDLK_BACKSLASH:
			return Key::Backslash;

		case SDLK_RIGHTBRACKET:
			return Key::RightBracket;

		case SDLK_a:
			return Key::A;

		case SDLK_b:
			return Key::B;

		case SDLK_c:
			return Key::C;

		case SDLK_d:
			return Key::D;

		case SDLK_e:
			return Key::E;

		case SDLK_f:
			return Key::F;

		case SDLK_g:
			return Key::G;

		case SDLK_h:
			return Key::H;

		case SDLK_i:
			return Key::I;

		case SDLK_j:
			return Key::J;

		case SDLK_k:
			return Key::K;

		case SDLK_l:
			return Key::L;

		case SDLK_m:
			return Key::M;

		case SDLK_n:
			return Key::N;

		case SDLK_o:
			return Key::O;

		case SDLK_p:
			return Key::P;

		case SDLK_q:
			return Key::Q;

		case SDLK_r:
			return Key::R;

		case SDLK_s:
			return Key::S;

		case SDLK_t:
			return Key::T;

		case SDLK_u:
			return Key::U;

		case SDLK_v:
			return Key::V;

		case SDLK_w:
			return Key::W;

		case SDLK_x:
			return Key::X;

		case SDLK_y:
			return Key::Y;

		case SDLK_z:
			return Key::Z;

		case SDLK_DELETE:
			return Key::Delete;

		case SDLK_KP_PERIOD:
			return Key::Decimal;

		case SDLK_KP_DIVIDE:
			return Key::Divide;

		case SDLK_KP_MULTIPLY:
			return Key::Multiply;

		case SDLK_KP_MINUS:
			return Key::Subtract;

		case SDLK_KP_PLUS:
			return Key::Add;

		case SDLK_KP_ENTER:
			return Key::NumpadEnter;

		case SDLK_KP_EQUALS:
			return Key::NumpadEquals;

		case SDLK_UP:
			return Key::ArrowUp;

		case SDLK_DOWN:
			return Key::ArrowDown;

		case SDLK_RIGHT:
			return Key::ArrowRight;

		case SDLK_LEFT:
			return Key::ArrowLeft;

		case SDLK_INSERT:
			return Key::Insert;

		case SDLK_HOME:
			return Key::Home;

		case SDLK_END:
			return Key::End;

		case SDLK_PAGEUP:
			return Key::PageUp;

		case SDLK_PAGEDOWN:
			return Key::PageDown;

		case SDLK_F1:
			return Key::F1;

		case SDLK_F2:
			return Key::F2;

		case SDLK_F3:
			return Key::F3;

		case SDLK_F4:
			return Key::F4;

		case SDLK_F5:
			return Key::F5;

		case SDLK_F6:
			return Key::F6;

		case SDLK_F7:
			return Key::F7;

		case SDLK_F8:
			return Key::F8;

		case SDLK_F9:
			return Key::F9;

		case SDLK_F10:
			return Key::F10;

		case SDLK_F11:
			return Key::F11;

		case SDLK_F12:
			return Key::F12;

		case SDLK_F13:
			return Key::F13;

		case SDLK_F14:
			return Key::F14;

		case SDLK_F15:
			return Key::F15;

		case SDLK_RSHIFT:
			return Key::RightShift;

		case SDLK_LSHIFT:
			return Key::LeftShift;

		case SDLK_RCTRL:
			return Key::RightControl;

		case SDLK_LCTRL:
			return Key::LeftControl;

		case SDLK_RALT:
			return Key::RightAlt;

		case SDLK_LALT:
			return Key::LeftAlt;

		case SDLK_SYSREQ:
			return Key::SysRq;

		case SDLK_MENU:
			return Key::AppMenu;

		case SDLK_POWER:
			return Key::Power;

		default:
			return Key::NoConvert;
	}

	return Key::NoConvert;
}

CEGUI::MouseButton SDLButtonToCEGUIButton( Uint8 sdlButton )
{
	switch ( sdlButton )
	{
		case SDL_BUTTON_LEFT:
			return CEGUI::MouseButton::LeftButton;

		case SDL_BUTTON_RIGHT:
			return CEGUI::MouseButton::RightButton;

		case SDL_BUTTON_MIDDLE:
			return CEGUI::MouseButton::MiddleButton;

		case SDL_BUTTON_X1:
			return CEGUI::MouseButton::X1Button;

		case SDL_BUTTON_X2:
			return CEGUI::MouseButton::X2Button;
	}

	return CEGUI::MouseButton::NoButton;
}

void GUI::onSDLEvent( SDL_Event& event )
{
	// NOTE:Variables CANNOT be created inside a switch statement!
	// We are making this variable for the text input.
	CEGUI::String cs;

	switch ( event.type )
	{
		case SDL_MOUSEMOTION:
			m_GUIContext->injectMousePosition( event.motion.x, event.motion.y );
			break;

		case SDL_KEYDOWN:
			m_GUIContext->injectKeyDown( SDLKeyToCEGUIKey( event.key.keysym.sym ) );
			break;

		case SDL_KEYUP:
			m_GUIContext->injectKeyDown( SDLKeyToCEGUIKey( event.key.keysym.sym ) );
			break;

		case SDL_TEXTINPUT:
			cs = CEGUI::String( ( CEGUI::utf8* ) event.text.text );

			for ( unsigned int i = 0; i < cs.size(); ++i )
			{
				m_GUIContext->injectChar( cs[i] );
			}

			break;

		case SDL_MOUSEBUTTONDOWN:
			m_GUIContext->injectMouseButtonDown( SDLButtonToCEGUIButton( event.button.button ) );
			break;

		case SDL_MOUSEBUTTONUP:
			m_GUIContext->injectMouseButtonUp( SDLButtonToCEGUIButton( event.button.button ) );
			break;
	}
}

void GUI::loadScheme( const std::string& schemeFile )
{
	CEGUI::SchemeManager::getSingleton().createFromFile( schemeFile );
}

void GUI::setFont( const std::string& fontFile )
{
	// We have to create the CEGUI font before we can set it.
	CEGUI::FontManager::getSingleton().createFromFile( fontFile + ".font" );
	m_GUIContext->setDefaultFont( fontFile );
}

//TODO: make a function that adds a widget to another widget
CEGUI::Window* GUI::createWidget( const std::string& type,
								  const glm::vec4& destRectPercent,
								  const glm::vec4& destRectPixel,
								  const std::string& name /*= ""*/ )
{
	CEGUI::Window* newWindow = CEGUI::WindowManager::getSingleton().createWindow( type, name );
	m_rootWindow->addChild( newWindow );
	// Caling this function so as not to duplicate code
	GUI::setWidgetDims( newWindow, destRectPercent, destRectPixel );
	return newWindow;
}

void GUI::setWidgetDims( CEGUI::Window* widget,
						 const glm::vec4& destRectPercent,
						 const glm::vec4& destRectPixel )
{
	// These are super ugly lines of code, but they are necessary to set the position and size of a widget.
	// We are utilizing the handy glm::vec4 class to streamline the parameters of this function.
	widget->setPosition( CEGUI::UVector2(
							 CEGUI::UDim( destRectPercent.x, destRectPixel.x ),
							 CEGUI::UDim( destRectPercent.y, destRectPixel.y ) ) );
	widget->setSize( CEGUI::USize(
						 CEGUI::UDim( destRectPercent.z, destRectPixel.z ),
						 CEGUI::UDim( destRectPercent.w, destRectPixel.w ) ) );
}

