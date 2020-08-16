#include "stdafx.h"
#include "Coin.h"

Coin::Coin() {
	isRed = false;
	coin = new Sprite("Resources/Image/coin-yellow.png");
	AddChild(coin);

	rect = coin->getRect();
}

Coin::Coin(bool isRed) {
	this->isRed = isRed;

	if (isRed) {
		coin = new Sprite("Resources/Image/coin-red.png");
	}
	else {
		coin = new Sprite("Resources/Image/coin-yellow.png");
	}
	AddChild(coin);

	rect = coin->getRect();
}

Coin::~Coin() {

}

void Coin::Update(float dTime) {
	Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime, getPosY());
}

void Coin::Render() {
	Object::Render();
	coin->Render();
}

bool Coin::getIsRed() {
	return isRed;
}