#pragma once

#include "Player.h"
#include "Vehicle.h"
#include "UI.h"

class Game
{
private:
	//Game states
	bool GameState_MainMenu;
	bool GameState_Play;
	bool GameState_EndDeath;
	bool GameState_EndWin;

	//Components
	sf::Vector2f windowDimensions;					//Main windowDimensions, used for positional calculations.
	sf::RenderWindow * window;						//RenderWindow object as a pointer. Value is assigned in RenderGame().
	sf::Texture levelTexture;						//The main texture used as the background of the game.
	sf::Sprite level;								//Sprite that holds the background texture and that is drawn to the screen.
	sf::RectangleShape levelEndZone;				//The rectangle used to detect if the player has safely made it across the roads.
	std::vector<sf::RectangleShape> levelBounds;	//The boundaries around the edge of the level.

	//Class Instances
	Player player;		//Player.cpp instance.
	Vehicle vehicle;	//Vehicle.cpp instance.
	UI ui;				//UI.cpp instance.

	//Internal
	void EventHandling();	//Function used to handle any events that do not involve drawing.
	void RenderGame();		//Function used to handle all of the drawing within the game.
	void InitializeGame();	//Setup for the level sprite and sprite/window scaling.
	void MainMenu();		//Creates a panel via UI::CreatePanel and draws it.
	void RestartGame();		//Resets all objects and stats in the game.
	void GameEnd(sf::String title);
	//Checks
	bool gameHasFocus = true;

public:
	//External
	void StartGame();

	Game();
	~Game();
};
