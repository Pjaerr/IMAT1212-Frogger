#include "Vehicle.h"


float Vehicle::DeltaTime()
{
	sf::Clock clock;

	for (;;)
	{
		sf::Time deltaTime = clock.restart();
		return deltaTime.asSeconds();
	}
}

void Vehicle::Movement()
{
	//0 to 440

	/*NEED RENDERING TO BEGIN BEFORE MOVEMENT OF VEHICLES BEGINS AS THE RENDERING ONLY STARTS WHEN THE WHILE LOOP HAS ENDED
	POSSIBLE SOLUTION IS MULTI-THREADING ALTHOUGH IT SHOULDN'T BE NEEDED.*/

	for (int i = 0; i < sizeof(Sprites); i++)
	{
		std::cout << "Checking Sprite: " << i << std::endl;

		if (Directions[i] == 1)
		{
			std::cout << "Moving Sprite: " << i << std::endl;

			while (Sprites[i].getPosition().x < 440)
			{
				Sprites[i].move(1.0f, 0);
			}
		}
	}
	
	
}

/*VehicleInstantiation() takes the number of sprites and textures to launch the game with. This method will initialise
the textures that are to be used within the game and will store them in a Textures vector. It will then call the Spawn()
method and pass in the number of sprites and textures so that the Spawn() method can allocate them to each other accordingly.*/
void Vehicle::VehicleInstantiation(int numOfSprites, int numOfTextures)
{
	/*Sets an array of textures here at start so that they can be pulled from in the 
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

	Spawn(numOfSprites, numOfTextures);
}

/*The Spawn() method takes the number of sprites and assigned at instantiation. It then loops through the creation of the sprites 
which includes a random texture from the Textures vector and a random direction between 0 and 1. (left and right respectively).
It also positions the newly created sprites according to their direction. (ie. left facing sprite goes at the top right of the 
road and right facing sprite the bottom left). It then passes off this newly created vector of sprites so that they can be used
by the Movement() function and the Game class.*/
void Vehicle::Spawn(int numOfSprites, int numOfTextures)
{
	
	srand(time(0));		//The seed used to generate random numbers. time(0) is time passed since start of unix time.

	int counter = 0;		//Counter used for the iteration through the texture and direction allocation.

	std::vector<sf::Sprite> sprites;		//Local sprites vector.
	std::vector<int> directions;			//Local directions vector.

	sprites.resize(sizeof(Textures));	//Sets the size of the sprites vector to be that of the supplied numOfSprites value.
	directions.resize(sizeof(sprites));	//Sets the size of the directions vector to be that of the number of elements in the sprites vector.

	do
	{
		/*Sets the texture of the current sprite in the loop to a random value from within the Textures vector.*/
		sprites[counter].setTexture(Textures[rand() % numOfTextures]);	

		directions[counter] = rand() % 2;		//Sets the direction to a random choice between 0 and 1.

		/*NOTE TO SELF: After placeholder values have been tested with, remember to set the position according to the 
		size of the window as the game will stretch to fit any resolution and so should the position
		of the objects.*/

		if (directions[counter] == 0)		//direction == 0 is left.
		{
			sprites[counter].setPosition(440, 140);			//Sets the position of the sprite to be at far right of the top road.
			sprites[counter].scale(-1.0f, 1.0f);			//Flips the sprite to be facing left-wards.

			/*Sets the origin of the sprite (where it is moved from) to the center of the image.*/
			sprites[counter].setOrigin((sprites[counter].getPosition().x / 2), (sprites[counter].getPosition().y / 2));
		}
		else if (directions[counter] == 1)		//direction == 1 is right.
		{
			sprites[counter].setPosition(0, 240);		//Sets the position of the sprite to be at close left of the bottom road.
		}

		counter++;
	} 
	while (counter <= numOfSprites);

	Sprites = sprites;		//Assigning the local sprites vector to the global Sprites vector.
	Directions = directions;

	//Movement(directions);
}

std::vector<sf::Sprite> Vehicle::getSprite()
{
	return Sprites;
}

Vehicle::Vehicle()
{
	VehicleInstantiation(4, 4);		//Makes the vectors 4 sprites and 4 textures large.
}

Vehicle::~Vehicle()
{
}
