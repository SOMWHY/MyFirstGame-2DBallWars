#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

using namespace std;
using namespace sf;
class Player
{
private:
	//variables
	//player
	Vector2f playerDir;
	float playerSpeed;
	float playerOutlineThickness;
	Color playerMainColor;
	Color playerOutlineColor;
	float playerRadius;
	CircleShape playerShape;
	//health
	RectangleShape healthBar;
	int playerHp;
	int oneHpWidth;
	//bullet
	Bullet bullet;
	//private func
	void InitPlayer();
	void InitHealth();
	void Move();
	void Dash();
	void UpdateHp();
public:
	//cons des
	Player();
	~Player();
	//get
	Vector2f GetPosition();
	FloatRect GetCollider();
	Bullet& GetBullet();
	int GetHp();
	//set
	void DecreaseHp(int damage);

	//func
	void Update(RenderWindow* window, View& view);
	void Render(RenderWindow* window);

};

