#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene() {
	background = 
		new Sprite("Resources/Image/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/Image/mainname.png");
	AddObject(title);
	title->setPos(275, 0);

	startButton = new Sprite("Resources/Image/in.png");
	AddObject(startButton);
	startButton->setCenter(300, 120, startButton);
	startButton->setPos(SCREEN_WIDTH / 2, 350);

	exitButton = new Sprite("Resources/Image/out.png");
	AddObject(exitButton);
	exitButton->setPos(SCREEN_WIDTH / 2, 500);
}

MainScene::~MainScene() {

}

void MainScene::Render() {
	background->Render();
	title->Render();
	startButton->Render();
	exitButton->Render();
}

void MainScene::Update(float dTime) {
	Scene::Update(dTime);

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

		if (startButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}

		if (exitButton->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}

	}
}