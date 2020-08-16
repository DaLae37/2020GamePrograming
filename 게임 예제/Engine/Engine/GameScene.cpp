#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() {
	score = 0;
	coinCounter = 0;

	backgroundInstatiate = false;
	bridgeInstantiate = false;
	obstacleInstantiate = true;

	obstacleInstDelayTimer = 0;
	coinInstDelayTimer = 0;

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
		AddUI(numArray[i]);
	}

	player = new Player();
	AddObject(player);
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
	player->Render();
	for (int i = 0; i < 4; i++) {
		numArray[i]->Render();
	}
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);

	UISetting();
	TimerSetting(dTime);
	OptimizationObject();
	InstantiateObject();
	CollisionCheck();
}

void GameScene::TimerSetting(float dTime) {
	coinInstDelayTimer += dTime;
	obstacleInstDelayTimer += dTime;
}

void GameScene::UISetting() {
	numArray[0]->setNum(score / 1000);
	numArray[1]->setNum(score / 100 % 10);
	numArray[2]->setNum(score / 10 % 10);
	numArray[3]->setNum(score % 10);
}

void GameScene::OptimizationObject() {
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			backgroundInstatiate = false;
			obstacleInstantiate = false;
			if (iter == backgroundList.end()) {
				break;
			}
		}
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

	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
			if (iter == coinList.end()) {
				break;
			}
		}
	}

	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);

			if (iter == obstacleList.end()) {
				break;

			}
		}
	}
}

void GameScene::CollisionCheck() {
	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			RemoveObject((*iter));
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);

			if ((*iter)->getIsRed()) {
				score += 10;
			}
			else {
				score += 1;
			}

			score %= 10000;

			if (iter == coinList.end()) {
				break;
			}
		}
	}

	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}
	}
}

void GameScene::InstantiateObject() {
	if (!backgroundInstatiate) {
		Background* background = new Background();
		background->setPos(SCREEN_WIDTH - 20, 0);
		backgroundList.push_back(background);
		AddObject(background);
		backgroundInstatiate = true;
	}

	if (!bridgeInstantiate) {
		Bridge* bridge = new Bridge();
		bridge->setPos(SCREEN_WIDTH - 20, 500);
		bridgeList.push_back(bridge);
		AddObject(bridge);
		bridgeInstantiate = true;
	}

	if (!obstacleInstantiate) {
		if (obstacleInstDelayTimer > 1.f) {
			obstacleInstDelayTimer = 0;
			coinCounter = 4;
			Obstacle* obstacle = new Obstacle(rand() % 2);
			obstacle->setPos(SCREEN_WIDTH + 50, 400);
			AddObject(obstacle);
			obstacleList.push_back(obstacle);
			obstacleInstantiate = true;
		}
	}

	if (coinCounter > 0) {
		if (coinInstDelayTimer > 0.1f) {
			coinCounter--;
			coinInstDelayTimer = 0;
			Coin* coin = new Coin(true);
			coin->setPos(SCREEN_WIDTH, 300);
			AddObject(coin);
			coinList.push_back(coin);
		}
	}
	else {
		if (coinInstDelayTimer > 0.1f) {
			coinInstDelayTimer = 0;
			Coin* coin = new Coin(false);
			coin->setPos(SCREEN_WIDTH, 400);
			AddObject(coin);
			coinList.push_back(coin);
		}
	}
}