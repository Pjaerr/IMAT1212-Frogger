#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	std::vector<sf::Texture> Textures;
	std::vector<sf::Sprite> Sprites;
	void Spawn(int numOfSprites, int numOfTextures);
	void VehicleInstantiation(int numOfSprites, int numOfTextures);
	void Movement();
	

public:
	std::vector<sf::Sprite> getSprite();
	Vehicle();
	~Vehicle();
};

