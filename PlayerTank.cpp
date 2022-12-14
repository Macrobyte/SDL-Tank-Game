#include "PlayerTank.h"
#include "Game.h"


PlayerTank::PlayerTank(const TextureLoader* pParamsBody, const TextureLoader* pParamsTurret) : SDLGameObject(pParamsBody)
{
	m_pTankBody = new TankBody(pParamsBody);
	m_pTankTurret = new TankTurret(pParamsTurret);
}

void PlayerTank::Draw()
{
	m_pTankBody->Draw();
	m_pTankTurret->Draw();
		
}

void PlayerTank::Update()
{
	m_pTankBody->Update();
	m_pTankTurret->Update();

	m_pTankTurret->SetPosition(m_pTankBody->GetCenter().x - m_pTankTurret->m_width / 2, m_pTankBody->GetCenter().y - m_pTankTurret->m_height / 2);

	SetPosition(m_pTankBody->GetX() , m_pTankBody->GetY());

	printf("X: %f , Y: %f \n", GetX(), GetY());
}

void PlayerTank::Clean()
{
	

}
