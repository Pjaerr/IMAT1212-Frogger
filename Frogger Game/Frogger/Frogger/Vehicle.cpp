#include "Vehicle.h"


/*NOTE TO SELF: Instead of, like in own documentation, having the game construct new vehicle objects for each vehicle
make it so the one vehicle object is constructed, and that manages the spawning of new cars. This is so any resources
that need to be used can be stored once on game start.*/


void Vehicle::Movement()
{
	/*Move this object in the Vehicle::direction at Vehicle::speed*/
}

void Vehicle::VehicleInstantiation()
{
	if (!texture.loadFromFile("resources/redCar.png"))
	{
	}
	else 
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(0, 240); //Placeholder. Moves car to relevant pos.

	/*Set a random speed, size, texture and direction here to the private variables relatively.*/
	//For a random texture, to avoid performance hits, load the textures on the first vehicles construction to a texture array
}

void Vehicle::Spawn(int direction, float speed, sf::Vector2f startingPos)
{
	/*In here spawn a random sprite, initialize its values using what is passed in and return the sprite
	which can then be drawn by the Game class and moved by the Movement function.*/
}

sf::Sprite Vehicle::getSprite()
{
	return sprite;
}

Vehicle::Vehicle()
{
	VehicleInstantiation();
	Movement();
}

Vehicle::~Vehicle()
{
}
