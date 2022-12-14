#pragma once
#include "SDLGameObject.h"
#include "TankBody.h"
#include "TankTurret.h"

#include "TextureManager.h"

class PlayerTank : public SDLGameObject
{
public:
	PlayerTank(const TextureLoader* pParams, const TextureLoader* pParams2);
	
	void Draw();
	
	void Update();
	
	void Clean();

	TankBody* m_pTankBody;
	TankTurret* m_pTankTurret;

private:
	
};


