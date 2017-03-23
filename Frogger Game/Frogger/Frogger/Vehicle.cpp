#include "Vehicle.h"

/*This is the function that moves the vehicles. It uses a movementSpeed float with which it will multiply by the time elapsed during the previous
frame and then move each sprite in the Sprites[] vector by that value. This results in smooth movement for the vehicles as they are being moved
along with the frame. Depending upon the direction of the sprite as per the Spawn() function, the movement will be carried out on negative or
positive values.*/
void Vehicle::Movement()
{
	/*Grabs the elasped time since the game clock was last restarted and then 
	assigns it as seconds to a float deltaTime. This acts as the time elapsed in
	the previous frame.*/
	sf::Time dt = clock.restart();
	float deltaTime = dt.asSeconds();

	float movementSpeed;	

	for (int i = 0; i < Sprites.size(); i++)
	{
		/*The furthest left on the screen moved further left by the width of a car, so that the cars spawn just off screen.*/
		float leftMostPos = -sizeOfCar;	
		/*The furthest right on the screen moved further right by the width of a car, so that the cars spawn just off screen.*/
		float rightMostPos = windowDimensions.x + sizeOfCar;

		if (Directions[i] == 0)
		{
			movementSpeed = 100;	//If the direction a car is facing is left, then move it slower.

			/*If the car has reached the left most position, move that car back to the right most position*/
			if (Sprites[i].getPosition().x < leftMostPos)
			{
				Sprites[i].setPosition(rightMostPos, Sprites[i].getPosition().y);
			}

			Sprites[i].move((-movementSpeed * deltaTime), 0);
		}
		else if (Directions[i] == 1)
		{
			movementSpeed = 140;	//If the direction a car is facing is right, then move it faster.

			/*If the car has reached the right most position, move that car back to the left most position*/
			if (Sprites[i].getPosition().x > rightMostPos)
			{
				Sprites[i].setPosition(leftMostPos, Sprites[i].getPosition().y);
			}

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

	Spawn(numOfSprites, 4);
}

/*The Spawn() method takes the number of sprites and assigned at instantiation. It then loops through the creation of the sprites 
which includes a random texture from the Textures vector and a random direction between 0 and 1. (left and right respectively).
It also positions the newly created sprites according to their direction. (ie. left facing sprite goes at the top right of the 
road and right facing sprite the bottom left). It then passes off this newly created vector of sprites so that they can be used
by the Movement() function and the Game class.*/
void Vehicle::Spawn(int numOfSprites, int numOfRoads)
{
	srand(time(0));		//The seed used to generate random numbers. time(0) is time passed since start of unix time.

	int counter = 0;		//Counter used for the iteration through the texture and direction allocation.

	Sprites.resize(numOfSprites);		//Sets the size of the Sprites vector to be that of the supplied numOfSprites value.
	Directions.resize(numOfSprites);	//Sets the size of the Directions vector to be that of the supplied numOfSprites value.

	/*Holds the start position of the vehicles depending upon which road they are on. Roads go from top
	to bottom as road[0]...road[1]*/
	std::vector<sf::Vector2f> road;
	road.resize(numOfRoads);

	road[0] = sf::Vector2f((windowDimensions.x + sizeOfCar), 40);	//MAKE SURE Y VALUE SCALES LIKE X VALUE
	road[1] = sf::Vector2f(-sizeOfCar, 220);	//MAKE SURE Y VALUE SCALES LIKE X VALUE
	road[2] = sf::Vector2f((windowDimensions.x + sizeOfCar), 400);	//MAKE SURE Y VALUE SCALES LIKE X VALUE
	road[3] = sf::Vector2f(-sizeOfCar, 580);	//MAKE SURE Y VALUE SCALES LIKE X VALUE

	do
	{
		/*Sets the texture of the current sprite in the loop to a random value from within the Textures vector.*/
		Sprites[counter].setTexture(Textures[rand() % Textures.size()]);	

		/*This string of if statements will check if the first quarter of the cars have been placed, if so, it will place the next quarter
		onto a new road, and then the next quarter and so on. It will variate the direction of the cars as per which road they are on.*/
		if (counter < (numOfSprites / 4))
		{
			Directions[counter] = 0;

			/*Passes in the current Sprite, the road it is being placed on and whether or not it needs to be flipped.*/
			positionSprites(Sprites[counter], road[0], true);

			/*Sets the starting position of the road to be shifted by the size of the car so that the next car does not spawn on top of another car.*/
			road[0].x = road[0].x + sizeOfCar;
		}
		else if (counter < ((numOfSprites / 4) + (numOfSprites / 4)))
		{
			Directions[counter] = 1;
			positionSprites(Sprites[counter], road[1], false);
			road[1].x = road[1].x - sizeOfCar;
		}
		else if (counter < ((numOfSprites / 4) + (numOfSprites / 4) + (numOfSprites / 4)))
		{
			Directions[counter] = 0;
			positionSprites(Sprites[counter], road[2], true);
			road[2].x = road[2].x + sizeOfCar;
		}
		else if (counter < ((numOfSprites / 4) + (numOfSprites / 4) + (numOfSprites / 4) + (numOfSprites / 4)))
		{
			Directions[counter] = 1;
			positionSprites(Sprites[counter], road[3], false);
			road[3].x = road[3].x - sizeOfCar;
		}

		counter++;
	} 
	while (counter < numOfSprites);
}

/*This function takes a sprite and positions it to a position that is passed in, it takes an extra parameter
that decides whether the sprite faces left or right.*/
void Vehicle::positionSprites(sf::Sprite& sprite, sf::Vector2f pos, bool isFlipped)
{
	if (isFlipped)
	{
		sprite.scale(-1.0f, 1.0f);	//Flips the sprite to be facing left.

		/*Sets the origin of the sprite (where it is moved from) to the center of the image.*/
		sprite.setOrigin((sprite.getPosition().x / 2), (sprite.getPosition().y / 2));
	}
	
	sprite.setPosition(pos);	//Sets the position of the sprite.
}

std::vector<sf::Sprite> Vehicle::getSprite()
{
	return Sprites;
}

Vehicle::Vehicle()
{
	VehicleInstantiation(28, 4);		//Makes the vectors 4 sprites and 4 textures large.
}

Vehicle::~Vehicle()
{
}
