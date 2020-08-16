#pragma once
#include "Object.h"
#include "Sprite.h"

class Coin : public Object
{
private :
	bool isRed;
	Sprite* coin;
public :
	Coin();
	Coin(bool isRed);
	~Coin();

	void Update(float dTime);
	void Render();

	bool getIsRed();
};