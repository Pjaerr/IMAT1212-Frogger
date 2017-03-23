#pragma once

#include "Player.h"
#include "Vehicle.h"

class Game
{
private:
	sf::Vector2f windowDimensions;
	sf::RenderWindow * window;	//RenderWindow object as a pointer. Value is assigned in RenderGame().
	sf::Texture levelTexture;	//The main texture used as the background of the game.
	sf::Sprite level;			//Sprite that holds the background texture and that is drawn to the screen.
	Player player;				//Player.cpp instance.
	Vehicle vehicle;			//Vehicle.cpp instance.
	void EventHandling();		//Function used to handle any events that do not involve drawing.
	void RenderGame();			//Function used to handle all of the drawing within the game.
	void InitializeLevel();		//Setup for the level sprite and sprite/window scaling.

public:
	void StartGame();
	Game();
	~Game();
};
