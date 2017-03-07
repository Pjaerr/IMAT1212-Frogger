#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	std::vector<sf::Texture> Textures;
	std::vector<sf::Sprite> Sprites;
	std::vector<int> Directions;
	void Spawn(int numOfSprites, int numOfTextures);
	void VehicleInstantiation(int numOfSprites, int numOfTextures);
	float DeltaTime();

public:
	std::vector<sf::Sprite> getSprite();
	void Movement();
	Vehicle();
	~Vehicle();
};

