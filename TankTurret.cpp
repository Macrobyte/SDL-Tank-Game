#include "TankTurret.h"
#include "InputHandler.h"
#include "Game.h"


TankTurret::TankTurret(const TextureLoader* pParams) : SDLGameObject(pParams) {}


void TankTurret::HandleInput()
{
	Vector2D* vector = InputHandler::GetMousePosition();
	float x = vector->GetX() - (m_position.GetX() + m_width / 2);
	float y = vector->GetY() - (m_position.GetY() + m_height / 2);
	m_rotation = 90 + atan2(y, x) * 180 / M_PI;
}


void TankTurret::Draw()
{
	TextureManager::Instance()->DrawTextureRotation(m_textureID, (int)m_position.GetX(), (int)m_position.GetY(), m_width, m_height, Game::Instance()->GetRenderer(), m_rotation);
}

void TankTurret::Update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100 % 8)));

	HandleInput();

	SDLGameObject::Update();
}

void TankTurret::Clean()
{
}