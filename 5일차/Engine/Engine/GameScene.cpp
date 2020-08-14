#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	score = 0;
	backgroundInstatiate = false;

	Background *background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	Sprite* tmpBridge = new Sprite("Resources/Image/LoopMap.png");
	tmpBridge->setPos(0, 500);
	bridgeList.push_back(tmpBridge);

	Sprite* tempBridge = new Sprite("Resources/Image/LoopMap.png");
	tempBridge->setPos(SCREEN_WIDTH, 500);
	bridgeList.push_back(tempBridge);

	Sprite* tmpCoin = new Sprite("Resources/Image/coin-yellow.png");
	tmpCoin->setPos(SCREEN_WIDTH + 70, 400);
	coinList.push_back(tmpCoin);

	Sprite* tmpObstacle = new Sprite("Resources/Image/Drop.png");
	tmpObstacle->setPos(SCREEN_WIDTH, 400);
	obstacleList.push_back(tmpObstacle);

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

	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}

	for (auto& coin : coinList) {
		coin->Render();
	}

	for (int i = 0; i < 4; i++) {
		numArray[i]->Render();
	}

	player->Render();
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);

	int randNum = rand() % 10 + 1;
	if (randNum == 1) {
		Sprite* tempCoin = new Sprite("Resources/Image/coin-yellow.png");
		tempCoin->setPos(SCREEN_WIDTH + 100, 400);
		coinList.push_back(tempCoin);
	}

	numArray[0]->setNum(score / 1000);
	numArray[1]->setNum(score / 100 % 10);
	numArray[2]->setNum(score / 10 % 10);
	numArray[3]->setNum(score % 10);

	player->Update(dTime);

	for (auto iter = backgroundList.begin();
		iter != backgroundList.end(); iter++) {
		
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
		background->setPos(SCREEN_WIDTH - 10, 0);
		backgroundList.push_back(background);
		AddObject(background);
		backgroundInstatiate = true;
	}

	int diff = 500 * dTime;
	for (auto iter = bridgeList.begin();
		iter != bridgeList.end(); iter++) {

		(*iter)->setPos((*iter)->getPosX() - diff,
			(*iter)->getPosY());

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);

			Sprite* tempBridge = new Sprite("Resources/Image/LoopMap.png");
			tempBridge->setPos(SCREEN_WIDTH, 500);
			bridgeList.push_back(tempBridge);

			if (iter == bridgeList.end()) {
				break;
			}
		}
	}

	for (auto iter = obstacleList.begin();
		iter != obstacleList.end(); iter++) {

		(*iter)->setPos((*iter)->getPosX() - diff,
			(*iter)->getPosY());

		if (player->IsCollisionRect((*iter))) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);

			Sprite* tempObstacle = new Sprite("Resources/Image/Drop.png");
			tempObstacle->setPos(SCREEN_WIDTH, 400);
			obstacleList.push_back(tempObstacle);

			if (iter == obstacleList.end()) {
				break;
			}
		}
	}

	for (auto iter = coinList.begin();
		iter != coinList.end(); iter++) {

		(*iter)->setPos((*iter)->getPosX() - diff,
			(*iter)->getPosY());

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);

			if (iter == coinList.end()) {
				break;
			}
		}
	}
	//새로만든coinList for문
	for (auto iter = coinList.begin();
		iter != coinList.end(); iter++) {

		if (player->IsCollisionRect((*iter))) {
			score += 1;
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);

			if (iter == coinList.end()) {
				break;
			}
		}
	}
}