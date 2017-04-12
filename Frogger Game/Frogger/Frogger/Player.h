#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
private:
	//Objects
	sf::Vector2f windowDimensions;			//Local windowDimensions.
	sf::Texture texture;					//Global texture that is assigned to sprite on PlayerInstantiation() call.
	sf::Sprite sprite;						//Global sprite that is drawn and moved.
	std::vector<sf::String> playerStats;	//The stats of the player as strings.

	//Attributes
	float movementSpeedX;		//The distance moved when on the X axis when a movement key is pressed.
	float movementSpeedY;		//The distance moved when on the Y axis when a movement key is pressed.
	int numOfLives;				//Number of lives the player has. Initialized in the constructor.
	int score;					//Score, incremented when player hits the level end zone.
	int scoreToWin;				//The score needed to be reached in order to win.
	sf::Vector2f scalingValue;	//The value by which to increase the player's size.

	//Checks
	bool isKeyDown = false;	//Used when moving the player, to stop constant free-form movement.
	
public:

	//Initialization
	Player();
	~Player();

	/*Called when creating the player, to pass in the required variables/objects*/
	void InstantiateClass(sf::Vector2f windowDimensions, int extNumOfLifes, int extScoreToWin);
	void SetPlayer(int extNumOfLifes);
	
	//Returning
	sf::Sprite getSprite();					//Returns the sf::Sprite sprite when called.
	std::vector<sf::String> getStats();		//Returns the player's stats as strings.
	bool isDead();							//Returns true if player has no more lifes.
	bool hasWon();							//Returns true if score == scoreToWin.

	//Internal
	void Movement(sf::Event event, bool gameHasFocus);	//Moves the player when called. Requires an sf::Event event to check for input.

	/*Checks for collision between the Player, vehicles, ending zone or level boundaries.*/
	void Collision(std::vector<sf::Sprite> vehicles, sf::RectangleShape levelEnd, std::vector<sf::RectangleShape> levelBounds);
	
};

