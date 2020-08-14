#include "stdafx.h"
#include "Player.h"

Player::Player() {
	isJump = false;
	doubleJump = false;
	gravity = 9.8;

	playerAnimation = new Animation(10);
	playerAnimation->AddFrame("Resources/Image/player-stop.png");
	playerAnimation->AddFrame("Resources/Image/player-run.png");
	AddChild(playerAnimation);

	rect = playerAnimation->getRect();
}

Player::~Player() {

}

void Player::Render() {
	Object::Render();
	playerAnimation->Render();
}

void Player::Update(float dTime) {
	gravity += 9.8f;

	setPos(getPosX(), getPosY() + gravity * dTime);

	if (isJump) {
		setPos(getPosX(), getPosY() - 300 * dTime);
		if (doubleJump) {
			setPos(getPosX(), getPosY() - 300 * dTime);
		}
		if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
			doubleJump = true;
		}
	}
	if (getPosY() > 350) {
		setPos(getPosX(), 350);
		doubleJump = false;
		isJump = false;
	}

	if (inputManager->GetKeyState(VK_UP) == KEY_DOWN) {
		if (getPosY() == 350) {
			isJump = true;
			gravity = 0;
		}
	}

	playerAnimation->Update(dTime);
}