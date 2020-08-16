#pragma once
#include "Object.h"
#include "Sprite.h"

class Bridge : public Object
{
private:
	Sprite* bridge;
public:
	Bridge();
	~Bridge();
	void Update(float dTime);
	void Render();
};