#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Vehicle
{
private:
	//Components
	sf::Vector2f windowDimensions;		//Local windowDimensions.
	sf::Clock clock;					//Used to measure time to aid with the movement of the vehicles.
	std::vector<sf::Texture> Textures;	//Holds all of the textures set during VehicleInstantiation().
	std::vector<sf::Sprite> Sprites;	//Holds all of the sprites set during the Spawn().
	std::vector<int> Directions;		//Holds all of the directions set during Spawn().

	//Attributes
	float spaceBetweenCars;				//The width of the gap between cars. Used in positional calculations.
	float movementSpeed;
	
	//Internal
	void Spawn(int numOfSprites, int numOfRoads);	//Function used to create the sprites and give them attributes.

	/*Function called from Vehicle::Spawn() to position and/or flip the sprites depending on what is passed in.*/
	void positionSprites(sf::Sprite& sprite, sf::Vector2f pos, bool isFlipped);	

public:
	//Returning
	std::vector<sf::Sprite> getSprite();	//Returns the vehicle sprites.

	//External
	void Movement(bool gameHasFocus);	//Moves the vehicle sprites when the window has focus.

	/*Acts as the constructor but separated to allow changes to the vehicle class without recreating it.*/
	void InstantiateVehicle(sf::Vector2f extWindowDimensions, int numOfSprites, int numOfTextures);	

	Vehicle();
	~Vehicle();
};

