#pragma once
#include "SDLGameObject.h"

class TankBody : public SDLGameObject
{

private:
	float tankSpeed;
	float m_angle;

	float deltaX;
	float deltaY;

	void HandleInput();

public:

	TankBody(const TextureLoader* pParams);

	void Draw();
	void Update();
	void Clean();
	
};

