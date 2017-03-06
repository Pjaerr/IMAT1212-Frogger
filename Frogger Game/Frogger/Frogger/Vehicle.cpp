#include "Vehicle.h"


/*NOTE TO SELF: Instead of, like in own documentation, having the game construct new vehicle objects for each vehicle
make it so the one vehicle object is constructed, and that manages the spawning of new cars. This is so any resources
that need to be used can be stored once on game start.*/


void Vehicle::Movement()
{

}

void Vehicle::VehicleInstantiation(int numOfTextures)
{
	/*Set an array of textures here at start so that they can be pulled from in the 
	Spawn() method when assigning textures.*/

	Textures.resize(numOfTextures);

	if (!Textures[0].loadFromFile("resources/redCar.png"))
	{
	}
	if (!Textures[1].loadFromFile("resources/blueCar.png"))
	{
	}
	if (!Textures[2].loadFromFile("resources/greenCar.png"))
	{
	}
	if (!Textures[3].loadFromFile("resources/yellowCar.png"))
	{
	}


	Spawn(4);
}

void Vehicle::Spawn(int maxSprites)
{
	/*Note to self: Make sure the texture allocation is random alongside the
	direction allocation as opposed to temporary linear allocation.*/

	int counter = 0;
	std::vector<sf::Sprite> sprites;
	std::vector<int> directions;

	sprites.resize(sizeof(Textures));
	directions.resize(sizeof(sprites));

	do
	{
		sprites[counter].setTexture(Textures[0]);
		directions[counter] = 0;

		/*After placeholder values have been tested with, remember to set the position according to the 
		size of the window as the game will stretch to fit any resolution and so should the position
		of the objects.*/

		if (directions[counter] == 0)
		{
			sprites[counter].setPosition(440, 100);
			sprites[counter].scale(-1.0f, 1.0f);
			sprites[counter].setOrigin((sprites[counter].getPosition().x / 2), (sprites[counter].getPosition().y / 2));
		}
		else if (directions[counter] == 1)
		{
			sprites[counter].setPosition(0, 240);
		}

		counter++;
	} 
	while (counter <= maxSprites);

	Sprites = sprites;
	
}

std::vector<sf::Sprite> Vehicle::getSprite()
{
	return Sprites;
}

Vehicle::Vehicle()
{
	VehicleInstantiation(4);
}

Vehicle::~Vehicle()
{
}
