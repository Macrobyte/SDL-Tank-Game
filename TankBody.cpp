#include "TankBody.h"
#include "InputHandler.h"
#include "Game.h"



TankBody::TankBody(const TextureLoader* pParams) : SDLGameObject(pParams)
{
	tankSpeed = 2.5f;

	m_angle = 0;

	deltaX = 0;

	deltaY = 0;

	
}

void TankBody::HandleInput()
{
	if (InputHandler::GetKey(SDL_SCANCODE_W))
	{		
		deltaX = -tankSpeed * cos(m_angle * (M_PI / 180));
		deltaY = -tankSpeed * sin(m_angle * (M_PI / 180));

		SetPosition(m_position.GetX() + deltaX, m_position.GetY() + deltaY);		
	}
	else if (InputHandler::GetKey(SDL_SCANCODE_S))
	{
		deltaX = tankSpeed * cos(m_angle * (M_PI / 180));
		deltaY = tankSpeed * sin(m_angle * (M_PI / 180));

		SetPosition(m_position.GetX() + deltaX, m_position.GetY() + deltaY);
	}
	else
	{
		m_velocity.SetY(0);
	}

	if (InputHandler::GetKey(SDL_SCANCODE_A))
	{
		m_angle--;
	}
	else if (InputHandler::GetKey(SDL_SCANCODE_D))
	{
		m_angle++;
	}
	
}

void TankBody::Draw()
{
	
	TextureManager::Instance()->DrawTextureRotation(m_textureID, (int)m_position.GetX(), (int)m_position.GetY(), m_width, m_height, Game::Instance()->GetRenderer(), m_angle);
	
	CollisionHandler::DrawCollisionRect(Game::Instance()->GetRenderer(), m_objectCollider);

}

void TankBody::Update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100 % 2)));
	
	HandleInput();

	SDLGameObject::Update();

}

void TankBody::Clean()
{
}


