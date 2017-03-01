#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
private:
	float movementSpeed; //Movement speed is multiplied by constant 0.01f.
	sf::Texture texture;
	sf::Sprite sprite;
	void PlayerInstantiation();
	
	
public:
	int numOfLives;
	sf::Sprite getSprite();
	void Movement();
	Player();
	Player(float movementSpeed, int numOfLives);
	~Player();
};

