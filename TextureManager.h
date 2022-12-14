#pragma once
#include "SDL.h"
#include <map>
#include <string>


class TextureManager
{
private:
	TextureManager() {}
	static TextureManager* s_pInstance;
	
	std::map<std::string, SDL_Texture*> m_textureMap;

public:
	bool LoadTexture(std::string fileName, std::string id, SDL_Renderer* renderer);
	void DrawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawTextureRotation(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, double angle, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
};

