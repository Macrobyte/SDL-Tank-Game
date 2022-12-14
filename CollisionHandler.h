#pragma once
#include "SDL.h"
#include <iostream>

class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	//Write a function that checks if two rectangles are colliding
	static bool CheckCollision(SDL_Rect a, SDL_Rect b);

	//Write a function that checks if a circle is colliding with another circle
	static bool CheckCollision(int x1, int y1, int radius1, int x2, int y2, int radius2);

	//Draw collision rectangle
	static void DrawCollisionRect(SDL_Renderer* pRenderer, SDL_Rect rect);

};

