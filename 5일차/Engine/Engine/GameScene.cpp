#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	score = 0;
	backgroundInstatiate = false;
	bridgeInstantiate = false;

	Background* background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	Bridge* bridge = new Bridge();
	bridge->setPos(0, 500);
	bridgeList.push_back(bridge);
	AddObject(bridge);

	for (int i = 0; i < 4; i++) {
		numArray[i] = new Number();
		numArray[i]->setPos(0 + 60 * i, 10);
	}

	player = new Player();
}

GameScene::~GameScene() {

}

void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}

	for (auto& bridge : bridgeList) {
		bridge->Render();
	}

	for (int i = 0; i < 4; i++) {
		numArray[i]->Render();
	}

	player->Render();
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);

	numArray[0]->setNum(score / 1000);
	numArray[1]->setNum(score / 100 % 10);
	numArray[2]->setNum(score / 10 % 10);
	numArray[3]->setNum(score % 10);

	player->Update(dTime);

	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			backgroundInstatiate = false;
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}

	if (!backgroundInstatiate) {
		Background* background = new Background();
		background->setPos(SCREEN_WIDTH - 15, 0);
		backgroundList.push_back(background);
		AddObject(background);
		backgroundInstatiate = true;
	}

	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);
			bridgeInstantiate = false;
			if (iter == bridgeList.end()) {
				break;
			}
		}
	}

	if (!bridgeInstantiate) {
		Bridge* bridge = new Bridge();
		bridge->setPos(SCREEN_WIDTH - 15, 500);
		bridgeList.push_back(bridge);
		AddObject(bridge);
		bridgeInstantiate = true;
	}
}