#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

//view
const float VIEW_HEIGHT = 4000.0f;
const float VIEW_WIDTH = VIEW_HEIGHT;
class Game
{
private:
	//window
	RenderWindow* window;
	VideoMode videoMode;
	//view
	View* view;
	//text msg
	Font sodaFont;
	Text menuTitle;
	Text menuStartGame;
	Text menuSettings;
	Text menuExitGame;
	Text msgYouDie;
	//variable
	bool gameOver;
	Event sfmlEv;
	Player player;
	Enemy enemy;
	//private func
	void InitVariables();
	void InitWindow();
	void InitText();
	void Resize();
	void PollEvents();

public:
	//constructor and destructor
	Game();
	~Game();

	//getters
	bool IsRunning();
	RenderWindow* GetWindow();
	Vector2i GetMousePos();
	//setters


	//func
	void Update();
	void Render();

};

