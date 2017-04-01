#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
private:

	//Objects
	sf::Vector2f windowDimensions;
	sf::Texture texture;	//Global texture that is assigned to sprite on PlayerInstantiation() call.
	sf::Sprite sprite;		//Global sprite that is drawn and moved.
	sf::Font font;
	std::vector<sf::String> playerStats;

	//Attributes
	float movementSpeed;	//Movement speed is the distance moved when a movement key is pressed.
	int numOfLives;			//Number of lives the player has. Initialized in the constructor.
	int score;				//Score, incremented when player hits the level end zone.
	sf::Vector2f scalingValue;	//The value by which to increase the player.

	//Checks
	bool isKeyDown = false;	//Used when moving the player, to stop constant free-form movement.
	bool isDead();			//Returns true if player has no more lifes.
	
	
public:

	//Initialization
	Player();
	~Player();
	void InstantiatePlayer(sf::Vector2f windowDimensions, float movementSpeed, int numOfLifes);
	
	//Returning
	sf::Sprite getSprite();			//Returns the sf::Sprite sprite when called.
	std::vector<sf::String> getStats();

	//Internal
	void Movement(sf::Event event);	//Moves the player when called. Requires an sf::Event event to check for input.
	void Collision(std::vector<sf::Sprite> vehicles, sf::RectangleShape levelEnd, std::vector<sf::RectangleShape> levelBounds);	//Checks for collision with the player.
	
};

