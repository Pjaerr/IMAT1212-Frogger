#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
private:
	
	sf::Vector2f windowDimensions;
	float movementSpeed;	//Movement speed is the distance moved when a movement key is pressed.
	sf::Texture texture;	//Global texture that is assigned to sprite on PlayerInstantiation() call.
	sf::Sprite sprite;		//Global sprite that is drawn and moved.
	bool isKeyDown = false;	//Used when moving the player, to stop constant free-form movement.
	int numOfLives;			//Number of lives the player has. Initialized in the constructor.
	int score;				//Score, incremented when player hits the level end zone.
	bool isDead();			//Returns true if player has no more lifes.
	
	
public:
	
	sf::Sprite getSprite();			//Returns the sf::Sprite sprite when called.
	void Movement(sf::Event event);	//Moves the player when called. Requires an sf::Event event to check for input.
	void Collision(std::vector<sf::Sprite> vehicles, sf::RectangleShape levelEnd);	//Checks for collision with the player.
	void InstantiatePlayer(sf::Vector2f windowDimensions, float movementSpeed, int numOfLifes);
	Player();
	~Player();
};

