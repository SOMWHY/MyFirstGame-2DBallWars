#include "Enemy.h"

void Enemy::InitEnemy()
{
srand(time(0));
enemySpeed = 7.f;
enemyMainColor = Color(500,0,50);
enemyOutlineColor = Color(0, 50,0);
enemyRadius = 50.f;
enemyOutlineThickness = 10.f;
enemyShape.setFillColor(enemyMainColor);
enemyShape.setOrigin(enemyRadius, enemyRadius);
enemyShape.setOutlineColor(enemyOutlineColor);
enemyShape.setOutlineThickness(enemyOutlineThickness);
enemyShape.setRadius(enemyRadius);


spawnTimer = 0.f;
spawnTime = 5.f;

hungryTime = 5000.f;
hungryTimer = 0.f;


oneHpWidth = 30;
enemyHp = 30;
healthBar.setFillColor(Color::Red);
healthBar.setSize(Vector2f(oneHpWidth * enemyHp / 10.f, oneHpWidth));
}
void Enemy::UpdateHp()
{
	for (size_t i = 0; i < enemies.size(); i++)
	{

	healthBar.setPosition(enemies[i].getPosition().x - 150.f, enemies[i].getPosition().y - 150.f);
	if (healthBar.getSize().x != 0)
		healthBar.setSize(Vector2f(enemyHp * oneHpWidth / 10.f, oneHpWidth));
	}
}
void Enemy::Spawn()
{
	spawnTimer++;
	if (spawnTimer > spawnTime) {

	enemyShape.setPosition(rand() % (0, 24000)-12000, rand() % (0,24000)-12000);
	enemies.push_back(enemyShape);
	
	spawnTimer = 0;
	}
}

void Enemy::Move()
{
	for (size_t i = 0; i < enemies.size(); i++)
	{

		enemies[i].setFillColor(Color(500, rand() % (0, 151), rand() % (0, 31)));
		enemies[i].setScale(rand()%(1,3)-0.8, 1);
		
		if (enemies.size() > 50&& enemies.size() < 150) {
			enemies[i].move(3 * enemySpeed,3 * enemySpeed);
		}
		else {
			enemies[i].move((-1 + rand() % (0, 3)) * enemySpeed, (-1 + rand() % (0, 3)) * enemySpeed);
		}
	}
}

void Enemy::Dash()
{
	
}

Enemy::Enemy()
{
	InitEnemy();
}

Enemy::~Enemy()
{

}



FloatRect Enemy::GetCollider()
{
	return enemyShape.getGlobalBounds();
}

void Enemy::Update()
{
	
	Spawn();
	Move();
	Dash(); 
	UpdateHp();
}

void Enemy::Render(RenderWindow* window)
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		window->draw(enemies[i]);
		window->draw(healthBar);
	}
}
