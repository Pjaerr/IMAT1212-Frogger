#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	std::vector<sf::Texture> Textures;
	std::vector<sf::Sprite> Sprites;
	void Spawn(int maxSprites);
	void VehicleInstantiation(int numOfTextures);
	void Movement();
	

public:
	std::vector<sf::Sprite> getSprite();
	Vehicle();
	~Vehicle();
};

