#include "Player.h"

void Player::InitPlayer()
{
	playerDir = Vector2f(0, 0);
	playerSpeed = 8.f;
	playerMainColor = Color::Cyan;
	playerOutlineColor = Color::Magenta;
	playerRadius = 80.f;
	playerOutlineThickness = 20.f;
	playerShape.setFillColor(playerMainColor);
	playerShape.setOrigin(playerRadius, playerRadius);
	playerShape.setOutlineColor(playerOutlineColor);
	playerShape.setOutlineThickness(playerOutlineThickness);
	playerShape.setRadius(playerRadius);
	
}

void Player::InitHealth()
{
	oneHpWidth = 30;
	playerHp = 100;
	healthBar.setFillColor(Color::Red);
	healthBar.setPosition(20.f,20.f);
	healthBar.setSize(Vector2f(oneHpWidth*playerHp/10.f,oneHpWidth));
}

void Player::Move()
{
	


	if (Keyboard::isKeyPressed(Keyboard::A))
		playerDir = Vector2f(-1, 0);
	if (Keyboard::isKeyPressed(Keyboard::D))
		playerDir = Vector2f(1, 0);
	if (Keyboard::isKeyPressed(Keyboard::W))
		playerDir = Vector2f(0, -1);
	if (Keyboard::isKeyPressed(Keyboard::S))
		playerDir = Vector2f(0, 1);

	if(Keyboard::isKeyPressed(Keyboard::A)|| Keyboard::isKeyPressed(Keyboard::D)||
		Keyboard::isKeyPressed(Keyboard::W)||
		Keyboard::isKeyPressed(Keyboard::S))
	playerShape.move(playerDir.x * playerSpeed, playerDir.y * playerSpeed);
}

void Player::Dash()
{
	if (Mouse::isButtonPressed(Mouse::Right)&&playerSpeed < 20.f) {
		playerSpeed += 5.f;
		
		if(playerDir.x==0)
		playerShape.setScale(0.95,1.05);
		else
		playerShape.setScale(1.05,0.95);
	}
	else { playerSpeed = 8.f; 
	playerShape.setScale(1,1);
	}
}

void Player::UpdateHp()
{
	healthBar.setPosition(playerShape.getPosition().x-150.f, playerShape.getPosition().y - 150.f);
	if(healthBar.getSize().x!=0)
	healthBar.setSize(Vector2f(playerHp * oneHpWidth/10.f, oneHpWidth));
}

FloatRect Player::GetCollider()
{
	return playerShape.getGlobalBounds();
}

Bullet& Player::GetBullet()
{
	// TODO: insert return statement here
	return bullet;
}

int Player::GetHp()
{
	return playerHp;
}

void Player::DecreaseHp(int damage)
{
	if(playerHp>0)
	playerHp -= damage;
	else {
		playerShape.setRadius(0);
		//show game over msg
	}
}

Player::Player()
{
	InitHealth();
	InitPlayer();
}

Player::~Player()
{
}

Vector2f Player::GetPosition()
{
	return playerShape.getPosition();
}

void Player::Update(RenderWindow* window, View& view)
{
	Dash();
	Move();
	UpdateHp();
	bullet.Update(window,playerShape,view);
}

void Player::Render(RenderWindow* window)
{
	window->draw(playerShape);
	window->draw(healthBar);
	bullet.Render(window);
}
