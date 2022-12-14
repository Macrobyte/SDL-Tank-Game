#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
}

bool CollisionHandler::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}


bool CollisionHandler::CheckCollision(int x1, int y1, int radius1, int x2, int y2, int radius2)
{
	//Calculate total radius squared
	int totalRadiusSquared = radius1 + radius2;
	totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

	//If the distance between the centers of the circles is less than the sum of their radii
	if (totalRadiusSquared > ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)))
	{
		//The circles have collided
		return true;
	}

	//If not
	return false;
}

void CollisionHandler::DrawCollisionRect(SDL_Renderer* pRenderer, SDL_Rect rect)
{
	//SDL_Rect outlineRect = rect;
	SDL_SetRenderDrawColor(pRenderer, 0x00, 0xFF, 0x00, 0xFF);
	//SDL_RenderFillRect(pRenderer, &rect);
	SDL_RenderDrawRect(pRenderer, &rect);

	
	SDL_SetRenderDrawColor(pRenderer, 0x00, 0x00, 0x00, 0xFF);
	
}
