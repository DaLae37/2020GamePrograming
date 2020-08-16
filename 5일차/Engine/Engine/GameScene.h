#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include <list>
//Object Headers
#include "Number.h"
#include "Player.h"
#include "Background.h"
#include "Bridge.h"

class GameScene : public Scene
{
private :
	int score;
	bool backgroundInstatiate, bridgeInstantiate;

	std::list<Background *> backgroundList;
	std::list<Bridge *> bridgeList;

	Number *numArray[4];
	Player* player;
public :
	GameScene();
	~GameScene();

	void Render();
	void Update(float dTime);
};