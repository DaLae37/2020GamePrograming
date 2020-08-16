#include "stdafx.h"
#include "Bridge.h"

Bridge::Bridge() {
	bridge = new Sprite("Resources/Image/LoopMap.png");
	AddChild(bridge);
}

Bridge::~Bridge() {

}

void Bridge::Render() {
	Object::Render();
	bridge->Render();
}

void Bridge::Update(float dTime) {
	Object::Update(dTime);
	setPos(getPosX() - RUNNING_SPEED *dTime, getPosY());
}