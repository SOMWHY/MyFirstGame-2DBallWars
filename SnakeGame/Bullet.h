#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using namespace sf;
class Bullet
{
private:
	//variables
	Vector2f direction;
	float vectorLength;
	float bulletSpeed;

	RectangleShape bullet;
	float bulletTimer;
	float bulletTime;
	//mouse
	Vector2i mousePos;
	Vector2f mousePosF;
	//bullets
	Vector2f everyBulletDir;
	float bulletDistance;
	//private func
	void InitBullet();
	void ClearBullet(CircleShape playerShape, float vectorLength);
	void Move(RenderWindow* window, CircleShape playerShape,View& view);


public:
	Bullet();
	~Bullet();
	//get
	vector<RectangleShape> bullets;
	
	//set


	//func
	void Update(RenderWindow* window, CircleShape playerShape, View& view);
	void Render(RenderWindow* window);
};

