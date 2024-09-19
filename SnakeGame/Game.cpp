#include "Game.h"

void Game::InitVariables()
{
	
	this->gameOver = false;
	this->view =new View(Vector2f(float(window->getSize().x/2), float(window->getSize().y / 2)),Vector2f(1000.f,1000.f) );
	
}

void Game::InitWindow()
{
	
	this->videoMode = VideoMode(1000, 1000);
	this->window = new RenderWindow(this->videoMode,"BallsWar",Style::Close| Style::Resize);
	window->setFramerateLimit(60);
}

void Game::InitText()
{

	if (!sodaFont.loadFromFile("fonts/CoffeeSoda.ttf"))
		throw "no font";
	
	msgYouDie.setFont(sodaFont);
	msgYouDie.setStyle(Text::Bold);
	msgYouDie.setFillColor(Color::White);
	msgYouDie.setOutlineColor(Color::Yellow);
	msgYouDie.setLineSpacing(0.3f);
	msgYouDie.setCharacterSize(300);
	msgYouDie.setString("You Die!");
	msgYouDie.setOrigin(msgYouDie.findCharacterPos(3).x, msgYouDie.findCharacterPos(3).y + msgYouDie.getCharacterSize() / 2);
	
}


void Game::PollEvents()
{
	
	while (window->pollEvent(this->sfmlEv))
	{
		switch (this->sfmlEv.type)
		{case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (sfmlEv.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		case Event::Resized:
			Resize();
			break;
		}
	}
}

Game::Game()
{
	InitWindow();
	InitVariables();
	InitText();
}

Game::~Game()
{
	delete this->window;
}
void Game::Resize()
{
	float aspectRatio = float(this->window->getSize().x) / float(this->window->getSize().y);
	view->setSize(window->getSize().y *aspectRatio, window->getSize().y);

	
	
}

bool Game::IsRunning()
{
	return this->window->isOpen();
}

RenderWindow* Game::GetWindow()
{
	return window;
}

Vector2i Game::GetMousePos()
{
	Vector2i mousePosition =Mouse::getPosition(*window);
	return mousePosition;
}

void Game::Update()
{	//window state update
	PollEvents();
	//game stuffs update
	player.Update(window,*view);
	enemy.Update();
	for (size_t i = 0; i < enemy.enemies.size(); i++)
	{
		CircleShape enemyEach = enemy.enemies[i];
		enemy.hungryTimer++;
		if (enemyEach.getGlobalBounds().intersects(player.GetCollider())) {
		


			player.DecreaseHp(1);
			enemy.hungryTimer = 0;
		}
		if (enemy.hungryTimer > enemy.hungryTime) {
			enemy.enemies.erase(enemy.enemies.begin() + i);
			enemy.hungryTimer = 0;
			break;
		}
		

		for (size_t j = 0; j < player.GetBullet().bullets.size(); j++)
			if (enemyEach.getGlobalBounds().intersects(player.GetBullet().bullets[j].getGlobalBounds())) {
			player.GetBullet().bullets.erase(player.GetBullet().bullets.begin() + j);
			enemy.enemies.erase(enemy.enemies.begin() + i);
			}
		
		
	}


	view->setCenter(player.GetPosition());
	msgYouDie.setPosition(view->getCenter().x, view->getCenter().y);
}

void Game::Render()
{
	this->window->clear(Color(5,17,33));
	this->window->setView(*this->view);
	//draw everything here
	if (player.GetHp() <= 0)
	{
	msgYouDie.setScale(view->getSize().x/1800.f, view->getSize().x / 1800.f);
	window->draw(msgYouDie);
	}
	
	player.Render(window);
	enemy.Render(window);
	
	this->window->display();
}
