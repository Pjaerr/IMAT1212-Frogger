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
	static int numOfLives;
	sf::Sprite sprite;
	Player(float movementSpeed, int numOfLives);
	~Player();
};

