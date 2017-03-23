#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
private:
	float movementSpeed;	//Movement speed is the distance moved when a movement key is pressed.
	sf::Texture texture;	//Global texture that is assigned to sprite on PlayerInstantiation() call.
	sf::Sprite sprite;		//Global sprite that is drawn and moved.
	bool isKeyDown = false;	//Used when moving the player, to stop constant free-form movement.
	int numOfLives;			//Number of lives the player has. Initialized in the constructor.
	void PlayerInstantiation();
	
public:
	sf::Sprite getSprite();			//Returns the sf::Sprite sprite when called.
	void Movement(sf::Event event);	//Moves the player when called. Requires an sf::Event event to check for input.
	Player();
	Player(float movementSpeed, int numOfLives);
	~Player();
};

