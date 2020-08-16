#include "stdafx.h"
#include "Obstacle.h"

Obstacle::Obstacle() {
	obstacle = new Sprite("Resources/Image/Drop.png");
	AddChild(obstacle);

	rect = obstacle->getRect();
}

Obstacle::Obstacle(int kind) {
	switch (kind) {
	case 0:
		obstacle = new Sprite("Resources/Image/Drop.png");
		break;
	case 1:
		obstacle = new Sprite("Resources/Image/Block.png");
		break;
	default:
		obstacle = new Sprite("Resources/Image/Drop.png");
		break;
	}
	AddChild(obstacle);

	rect = obstacle->getRect();
}

Obstacle::~Obstacle() {

}

void Obstacle::Update(float dTime) {
	Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED * dTime, getPosY());
}

void Obstacle::Render() {
	Object::Render();
	obstacle->Render();
}