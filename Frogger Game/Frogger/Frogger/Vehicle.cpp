#include "Vehicle.h"

/*This is the function that moves the vehicles. It takes a movementSpeed float with which it will multiply by the time elapsed during the previous
frame and then move each sprite in the Sprites[] vector by that value. This results in smooth movement for the vehicles as they are being moved
along with the frame. Depending upon the direction of the sprite as per the Spawn() function, the movement will be carried out on negative or
positive values.*/
void Vehicle::Movement(float movementSpeed)
{
	/*Grabs the elasped time since the game clock was last restarted and then 
	assigns it as seconds to a float deltaTime. This acts as the time elapsed in
	the previous frame.*/
	sf::Time dt = clock.restart();
	float deltaTime = dt.asSeconds();

	for (int i = 0; i < Sprites.size(); i++)
	{
		float leftMostPos = -Sprites[i].getGlobalBounds().width;
		float rightMostPos = 440 + Sprites[i].getGlobalBounds().width;

		if (Directions[i] == 0)
		{
			if (Sprites[i].getPosition().x < leftMostPos)
			{
				Sprites[i].setPosition(rightMostPos, Sprites[i].getPosition().y);
			}
			//std::cout << "Moving Sprite: " << i << " at " << (movementSpeed * deltaTime) << " speed" << std::endl;
			Sprites[i].move((-movementSpeed * deltaTime), 0);
		}
		else if (Directions[i] == 1)
		{
			if (Sprites[i].getPosition().x > rightMostPos)
			{
				Sprites[i].setPosition(leftMostPos, Sprites[i].getPosition().y);
			}
			//std::cout << "Moving Sprite: " << i << " at " << (movementSpeed * deltaTime) << " speed" << std::endl;
			Sprites[i].move((movementSpeed * deltaTime), 0);
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


	for (int i = 0; i < numOfTextures; i++)
	{
		if (!Textures[i].loadFromFile("resources/vehicletex/" + std::to_string(i) + ".png"))
		{
		}
	}
	

	Spawn(numOfSprites, numOfTextures, 2);
}

/*The Spawn() method takes the number of sprites and assigned at instantiation. It then loops through the creation of the sprites 
which includes a random texture from the Textures vector and a random direction between 0 and 1. (left and right respectively).
It also positions the newly created sprites according to their direction. (ie. left facing sprite goes at the top right of the 
road and right facing sprite the bottom left). It then passes off this newly created vector of sprites so that they can be used
by the Movement() function and the Game class.*/
void Vehicle::Spawn(int numOfSprites, int numOfTextures, int numOfRoads)
{
	
	srand(time(0));		//The seed used to generate random numbers. time(0) is time passed since start of unix time.

	int counter = 0;		//Counter used for the iteration through the texture and direction allocation.

	std::vector<sf::Sprite> sprites;		//Local sprites vector.
	std::vector<int> directions;			//Local directions vector.

	sprites.resize(numOfSprites);		//Sets the size of the sprites vector to be that of the supplied numOfSprites value.
	directions.resize(numOfSprites);	//Sets the size of the directions vector to be that of the number of elements in the sprites vector.

	/*Holds the start position of the vehicles depending upon which road they are on. Roads go from top
	to bottom as roadStartingPos[0]...roadStartingPos[1]*/
	std::vector<float> roadStartingPos;
	roadStartingPos.resize(numOfRoads);
	roadStartingPos[0] = 440;	//Cars spawn at the far right of the road initially. 
	roadStartingPos[1] = 0;		//Cars spawn at the far left of the road initially.

	do
	{
		/*Sets the texture of the current sprite in the loop to a random value from within the Textures vector.*/
		sprites[counter].setTexture(Textures[rand() % numOfTextures]);	

		directions[counter] = rand() % 2;		//Sets the direction to a random choice between 0 and 1.

		if (directions[counter] == 0)		//direction == 0 is left.
		{
			sprites[counter].setPosition(roadStartingPos[0], 140);			//Sets the position of the sprite to be at far right of the top road.
			sprites[counter].scale(-1.0f, 1.0f);			//Flips the sprite to be facing left-wards.

			/*Sets the origin of the sprite (where it is moved from) to the center of the image.*/
			sprites[counter].setOrigin((sprites[counter].getPosition().x / 2), (sprites[counter].getPosition().y / 2));

			roadStartingPos[0] = sprites[counter].getPosition().x + sprites[counter].getGlobalBounds().width;
		
		}
		else if (directions[counter] == 1)		//direction == 1 is right.
		{
			
			sprites[counter].setPosition(roadStartingPos[1], 240);		//Sets the position of the sprite to be at close left of the bottom road.
			roadStartingPos[1] = sprites[counter].getPosition().x - sprites[counter].getGlobalBounds().width;
		}

		counter++;
	} 
	while (counter < numOfSprites);

	Sprites = sprites;			//Assigning the local sprites vector to the global Sprites vector.
	Directions = directions;	//Assigning the local directions vector to the global Directions vector.
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
