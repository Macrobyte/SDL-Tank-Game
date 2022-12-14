#pragma once
#include "TextureLoader.h"

class GameObject
{

public:
	
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Clean() = 0;
	
	
protected:
	GameObject(const TextureLoader* pParams) {}
	virtual ~GameObject() {}

};

