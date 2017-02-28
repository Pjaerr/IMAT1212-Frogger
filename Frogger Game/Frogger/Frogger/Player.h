#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
private:
	float movementSpeed;
	sf::Texture texture;
	void PlayerInstantiation();
	void Movement();
	
public:
	int numOfLives;
	sf::Sprite sprite;
	Player();
	Player(float movementSpeed, int numOfLives);
	~Player();
};

