#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const TextureLoader* pParams) 
	: GameObject(pParams), m_position((float)pParams->GetX(), (float)pParams->GetY()), m_velocity(0, 0), m_acceleration(0, 0)
{
	m_width = pParams->GetWidth();
	m_height = pParams->GetHeight();

	m_textureID = pParams->GetTextureID();

	m_currentRow = 1;	
	m_currentFrame = 1;

	m_rotation = 0;
	
	m_objectCollider = { (int)m_position.GetX(), (int)m_position.GetY(), m_width, m_height };
	
};

void SDLGameObject::Draw()
{
	TextureManager::Instance()->DrawFrame(m_textureID, (int)m_position.GetX(), (int)m_position.GetY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer());

}

void SDLGameObject::Update()
{
	m_velocity += m_acceleration;
	
	m_position += m_velocity;

	m_objectCollider = { (int)m_position.x , (int)m_position.y, m_width, m_height };

	//printf("%d , %d , %d , %d\n", m_objectCollider.x, m_objectCollider.y, m_objectCollider.w, m_objectCollider.h);
}

void SDLGameObject::Clean()
{

}

void SDLGameObject::SetPosition(float Xcoord, float Ycoord)
{
	m_position.SetX(Xcoord);
	m_position.SetY(Ycoord);
}

float SDLGameObject::GetX()
{
	return m_position.GetX();
}

float SDLGameObject::GetY()
{
	return m_position.GetY();
}

Vector2D SDLGameObject::GetPosition()
{
	return m_position;
}

Vector2D SDLGameObject::GetCenter()
{
	return Vector2D(m_position.GetX() + m_width / 2, m_position.GetY() + m_height / 2);
}

SDL_Rect* SDLGameObject::GetCollisionRect()
{
	return &m_objectCollider;
}



