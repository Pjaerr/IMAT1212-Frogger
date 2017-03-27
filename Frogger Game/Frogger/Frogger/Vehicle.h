#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	
	sf::Vector2f windowDimensions;
	float spaceBetweenCars;				//The width of the gap between cars. Used in positional calculations.
	sf::Clock clock;					//Used to measure time to aid with the movement of the vehicles.
	std::vector<sf::Texture> Textures;	//Holds all of the textures set during VehicleInstantiation().
	std::vector<sf::Sprite> Sprites;	//Holds all of the sprites set during the Spawn().
	std::vector<int> Directions;		//Holds all of the directions set during Spawn().

	void Spawn(int numOfSprites, int numOfRoads);	//Function used to create the sprites and give them attributes.
	void positionSprites(sf::Sprite& sprite, sf::Vector2f pos, bool isFlipped);	//Function called from Vehicle::Spawn() to position and/or flip the sprites.

public:
	std::vector<sf::Sprite> getSprite();
	void Movement();
	void InstantiateVehicle(int numOfSprites, int numOfTextures, sf::Vector2f extWindowDimensions);	//The constructor but separated for abstraction.
	Vehicle();
	~Vehicle();
};

