#pragma once
#include "SDLGameObject.h"


class TankTurret : public SDLGameObject
{

private:
	void HandleInput();

	
public:
	TankTurret(const TextureLoader* pParams);

	void Draw();
	void Update();
	void Clean();
	
};

