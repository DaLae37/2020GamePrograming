#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "GameScene.h"
//Object
#include "Font.h"
class MainScene : public Scene
{
public :
	MainScene();
	~MainScene();

	Sprite* background;
	Sprite* startButton;
	Sprite* exitButton;
	Sprite* title;

	Font* font;

	void Render();
	void Update(float dTime);
};