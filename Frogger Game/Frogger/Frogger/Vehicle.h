#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	
	sf::Vector2f windowDimensions = sf::Vector2f(1024, 768); //TEMP VARIABLE

	float sizeOfCar = 196;				//The width of a vehicle in the game. Used in positional calculations. (196x196)
	sf::Clock clock;					//Used to measure time to aid with the movement of the vehicles.
	std::vector<sf::Texture> Textures;	//Holds all of the textures set during VehicleInstantiation().
	std::vector<sf::Sprite> Sprites;	//Holds all of the sprites set during the Spawn().
	std::vector<int> Directions;		//Holds all of the directions set during Spawn().
	void Spawn(int numOfSprites, int numOfRoads);	//Function used to create the sprites and give them attributes.
	void VehicleInstantiation(int numOfSprites, int numOfTextures);	//The constructor but separated for abstraction.
	void positionSprites(sf::Sprite& sprite, sf::Vector2f pos, bool isFlipped);	//Function called from Vehicle::Spawn() to position and/or flip the sprites.

public:
	std::vector<sf::Sprite> getSprite();
	void Movement();
	Vehicle();
	~Vehicle();
};

