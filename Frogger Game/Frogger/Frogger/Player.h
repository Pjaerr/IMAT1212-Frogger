#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Vehicle.h"

class Player
{
private:
	Vehicle vehicle;
	float movementSpeed; //Movement speed is the distance moved when a movement key is pressed.
	sf::Texture texture;	//Global texture that is assigned to sprite on PlayerInstantiation() call.
	sf::Sprite sprite;	//Global sprite that is drawn and moved.
	bool isKeyDown = false;	//Used when moving the player, to stop constant free-form movement.
	void PlayerInstantiation();
	
public:
	int numOfLives;
	sf::Sprite getSprite();
	void Movement(sf::Event event);
	Player();
	Player(float movementSpeed, int numOfLives);
	~Player();
};

