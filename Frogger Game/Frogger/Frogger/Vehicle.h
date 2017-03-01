#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void Spawn(int direction, float speed, sf::Vector2f startingPos);
	void VehicleInstantiation();
	

public:
	sf::Sprite getSprite();
	void Movement();
	Vehicle();
	~Vehicle();
};

