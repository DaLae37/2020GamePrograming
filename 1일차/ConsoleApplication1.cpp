#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
using namespace std;

class Car {
private:
	int speed; // 속도
	int gear; // 기어
	string color; // 색상
	int* p;
	const int MAX_SPEED;

public:
	Car(int s, int g, string c);
	Car() : MAX_SPEED(200){
		cout << "생성자 호출" << endl;
		speed = 0;
		gear = 1;
		color = "white";
	}
	~Car() {
		cout << "소멸자 호출" << endl;
		delete p;
	}

	int getSpeed();
	void setSpeed(int s);
	int getGear();
	void setGear(int g);
	string getColor();
	void setColor(string c);

	void speedUp();
	void speedDown();
	void init(int s, int gear, string c);
	void show();
};

Car::Car(int s, int g, string c) : 
	speed(s), gear(g), color(c), MAX_SPEED(200){
}

int Car::getSpeed() {
	return speed;
}

void Car::setSpeed(int s) {
	speed = s;
}

int Car::getGear() {
	return gear;
}

void Car::setGear(int g) {
	gear = g;
}

string Car::getColor() {
	return color;
}

void Car::setColor(string c) {
	color = c;
}

void Car::speedUp() {
	speed += 10;
}

void Car::speedDown() {
	speed -= 10;
}

void Car::init(int s, int g, string c) {
	speed = s;
	gear = g;
	color = c;
}

void Car::show() {
	cout << "==========" << endl;
	cout << "속도 : " << speed << endl;
	cout << "기어 : " << gear << endl;
	cout << "색상 : " << color << endl;
	cout << "==========" << endl;
}

int main() {
	srand(time(NULL));
	srand(GetTickCount());

	Car car1(rand()%200, 1, "white"), car2(rand() % 200, 1, "red");
	Car* a = new Car();

	car1.show();
	car2.show();

	if (car1.getSpeed() > car2.getSpeed()) {
		cout << "car1이 승리함" << endl;
	}
	else {
		cout << "car2가 승리함" << endl;
	}
	delete a;
	return 0;
}