#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include <math.h>
#include "CollisionHandler.h"

class SDLGameObject : public GameObject
{
public:

	SDLGameObject(const TextureLoader* pParams);
	
	virtual void Draw();
	virtual void Update();
	virtual void Clean();

	void SetPosition(float Xcoord, float Ycoord);
	
	float GetX();
	float GetY();
	Vector2D GetPosition();
	
	Vector2D GetCenter();
	
	SDL_Rect* GetCollisionRect();

	int m_width;
	int m_height;
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	
	
	SDL_Rect m_objectCollider;
	
	float m_rotation;

	int m_currentRow;
	int m_currentFrame;
		
	std::string m_textureID;

};

