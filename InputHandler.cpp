#include "InputHandler.h"

Uint8* InputHandler::m_prevKeystates = nullptr;
const Uint8* InputHandler::m_keystates = nullptr;

Vector2D* InputHandler::m_mousePosition = nullptr;
std::vector<bool> InputHandler::m_mouseButtonStates = std::vector<bool>(MOUSE_TOTAL_BUTTONS);


void InputHandler::Initialize()
{
	printf("Initializing Input Handler...\n");

	//mouse input
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}

	m_mousePosition = new Vector2D(0, 0);

	//keyboard input
	m_keystates = SDL_GetKeyboardState(0);
	
	m_prevKeystates = new Uint8[SDL_NUM_SCANCODES];
	memcpy(m_prevKeystates, m_keystates, SDL_NUM_SCANCODES);
}

void InputHandler::Update()
{
	
	SDL_memcpy(m_prevKeystates, m_keystates, SDL_NUM_SCANCODES);
	
}

void InputHandler::Clean()
{
	printf("Cleaning up Input Handler...\n");
	
	delete m_mousePosition;
	delete[] m_prevKeystates;
}

void InputHandler::OnMouseMove(SDL_Event& event)
{
	m_mousePosition->SetX(event.motion.x);
	m_mousePosition->SetY(event.motion.y);
	
}

void InputHandler::GetMouseButtonDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::GetMouseButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

bool InputHandler::GetKey(SDL_Scancode key)
{	
	return m_keystates[key];
}

bool InputHandler::GetKeyDown(SDL_Scancode key)
{
	
	return m_keystates[key] && !m_prevKeystates[key];
}

bool InputHandler::GetKeyUp(SDL_Scancode key)
{
	return !m_keystates[key] && m_prevKeystates[key];
		
}


