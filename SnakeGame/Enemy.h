#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Player.h"
using namespace std;
using namespace sf;
class Enemy
{
private:
	//variables
	//enemy
	float enemySpeed;
	float enemyOutlineThickness;
	Color enemyMainColor;
	Color enemyOutlineColor;
	float enemyRadius;
	CircleShape enemyShape;
	float spawnTimer;
	float spawnTime;
	//health
	RectangleShape healthBar;
	int enemyHp;
	int oneHpWidth;
	//private func
	void InitEnemy();
	void Spawn();
	void Move();
	void Dash();
	void UpdateHp();
public:
	vector<CircleShape> enemies;
	vector<RectangleShape> hpBars;
	float hungryTime;
	float hungryTimer;
	//cons des
	Enemy();
	~Enemy();
	//get
	
	FloatRect GetCollider();

	//set


	//func
	void Update();
	void Render(RenderWindow* window);

};

