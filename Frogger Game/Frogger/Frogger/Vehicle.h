#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	sf::Clock clock;					//Used to measure time to aid with the movement of the vehicles.
	std::vector<sf::Texture> Textures;	//Holds all of the textures set during VehicleInstantiation().
	std::vector<sf::Sprite> Sprites;	//Holds all of the sprites set during the Spawn().
	std::vector<int> Directions;		//Holds all of the directions set during Spawn().
	void Spawn(int numOfSprites, int numOfTextures, int numOfRoads);	//Function used to create the sprites and give them attributes.
	void VehicleInstantiation(int numOfSprites, int numOfTextures);	

public:
	std::vector<sf::Sprite> getSprite();
	void Movement(float movementSpeed);
	Vehicle();
	~Vehicle();
};

