#include "TextureManager.h"
#include "SDL_image.h"



TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::LoadTexture(std::string fileName, std::string id, SDL_Renderer* renderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	
	//If the image didn't load
	if (pTempSurface == 0)
	{
		printf("Failed to load image: %s\n", fileName.c_str());
		return false;
	}


	//Copy the texture to the renderer
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pTempSurface);
	
	//Free temporary surface from memory
	SDL_FreeSurface(pTempSurface);

	//If image is loaded fine added to our list
	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}

void TextureManager::DrawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, double angle, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = destinationRect.w = width;
	sourceRect.h = destinationRect.h = height;

	destinationRect.x = x;
	destinationRect.y = y;

	SDL_RenderCopyEx(renderer, m_textureMap[id], &sourceRect, &destinationRect, angle, 0, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, double angle, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;
	


	

	sourceRect.x = width * currentFrame;
	sourceRect.y = height * (currentRow - 1);
	sourceRect.w = destinationRect.w = width;
	sourceRect.h = destinationRect.h = height;

	destinationRect.x = x;
	destinationRect.y = y;

	SDL_RenderCopyEx(renderer, m_textureMap[id], &sourceRect, &destinationRect, angle, 0, flip);
}

void TextureManager::DrawTextureRotation(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, double angle, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;
	
	/*SDL_Point center;
	
	center.x = width / 2;
	center.y = height / 2 + 20;*/
	
	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = destinationRect.w = width;
	sourceRect.h = destinationRect.h = height;

	destinationRect.x = x;
	destinationRect.y = y;

	SDL_RenderCopyEx(renderer, m_textureMap[id], &sourceRect, &destinationRect, angle, 0, flip);
}
