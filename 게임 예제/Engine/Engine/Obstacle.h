#pragma once
#include "Object.h"
#include "Sprite.h"

enum class OBSTACLES{
	STORM,
	BUILDING,
}; //Ãß°¡

class Obstacle : public Object
{
private :
	Sprite* obstacle;
	OBSTACLES obstacles;
public :
	Obstacle();
	Obstacle(int kind);
	~Obstacle();

	void Update(float dTime);
	void Render();
};