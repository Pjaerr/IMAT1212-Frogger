#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	int direction;
	float speed;
	int size;
	sf::Texture texture;
	void VehicleInstantiation();
	void Movement();

public:
	sf::Sprite sprite;
	Vehicle();
	~Vehicle();
};

