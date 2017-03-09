#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
private:
	float movementSpeed; //Movement speed is multiplied by constant 0.01f.
	sf::Texture texture;	//Global texture that is assigned to sprite on PlayerInstantiation() call.
	sf::Sprite sprite;	//Global sprite that is drawn and moved.
	void PlayerInstantiation();
	bool isKeyDown = false;	//Used when moving the player, to stop constant free-form movement.
	
	
public:
	int numOfLives;
	sf::Sprite getSprite();
	void Movement(sf::Event event);
	Player();
	Player(float movementSpeed, int numOfLives);
	~Player();
};

