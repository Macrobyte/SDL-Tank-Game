#pragma once
#include "SDL.h"
#include <vector>

#include "GameObject.h"
#include "PlayerTank.h"


class Game
{
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	};
	
	bool InitializeSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void Render();
	void Update();
	void HandleEvents();
	void Clean();
	void Quit();
	
	bool IsRunning() { return m_IsRunning; }
	SDL_Renderer* GetRenderer() const { return m_sdlRenderer; }
	
private:
	
	Game(){};
	~Game(){};
	
	static Game* s_pInstance;

	SDL_Window* m_sdlWindow = nullptr;
	SDL_Renderer* m_sdlRenderer = nullptr;
	
	SDL_Texture* m_sdlTexture = nullptr;
	
	int m_ScreenWidth = 800, m_ScreenHeight = 600;

	bool m_IsRunning = false;
	
	int m_CurrentFrame = 0;

	std::vector<GameObject*> m_GameObjects;

	GameObject* m_TankBody = nullptr;
	GameObject* m_TankTurret = nullptr;
	
	GameObject* m_Tank = nullptr;
		

};


