#pragma once

#include "SDL.h"
#include "Vector2D.h"
#include <vector>

enum MouseButtons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2,
	MOUSE_TOTAL_BUTTONS = 3
};


class InputHandler
{
private:
	static std::vector<bool> m_mouseButtonStates;	
	
	static Vector2D* m_mousePosition;
	
	//keyboard input
	static const Uint8* m_keystates;
	static Uint8* m_prevKeystates;
	
	
public:

	static void Initialize();
	static void Update();
	static void Clean();
	
	
	//Mouse Input
	static void OnMouseMove(SDL_Event& event);
	static void GetMouseButtonDown(SDL_Event& event);
	static void GetMouseButtonUp(SDL_Event& event);

	//Keyboard Input
	static bool GetKey(SDL_Scancode key);
	static bool GetKeyDown(SDL_Scancode key);
	static bool GetKeyUp(SDL_Scancode key);
	
	
	static Vector2D* GetMousePosition() { return m_mousePosition; }
};

