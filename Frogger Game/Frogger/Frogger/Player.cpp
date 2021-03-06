#include "Player.h"

/*The default constructor will set the player attributes by default.*/
Player::Player()
{
}
Player::~Player()
{
}

/*Initializes the player class. Takes in window dimensions, movement speed, number of lives and the max score needed to win.
These passed in values are then assigned to be used locally.*/
void Player::InstantiateClass(sf::Vector2f extWindowDimensions, int extNumOfLifes, int extScoreToWin)
{
	windowDimensions = extWindowDimensions;	//Sets the Player::windowDimensions to the window dimensions passed into this function.
	movementSpeedX = (windowDimensions.x * 0.044f);	//Sets the Player::movementSpeedX to the movement speed as per window resolution.
	movementSpeedY = (windowDimensions.y * 0.0586f);	//Sets the Player::movementSpeedY to the movement speed as per window resolution.
	scoreToWin = extScoreToWin;				//Sets the Player::scoreToWin to the score needed to win passed into this function.

	scalingValue = sf::Vector2f(1.05f, 1.05f);	//Sets the scaling value used in this class.

	if (!texture.loadFromFile("resources/frogTexture.png"))
	{
	}
	else
	{
		sprite.setTexture(texture);
	}

	/*Sets the origin of the sprite once to be the centre of the image.*/
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

	/*Calls the SetPlayer() function that sets the player attributes*/
	SetPlayer(extNumOfLifes);
}

/*Function that sets the score to 0, sets the number of lives to the number of lives
that were passed in. It also initialises the playerStats strings so that they can be used via UI. It will set
the player's default size and default position. Called in InstantiateClass, but also called when the game needs
to be restarted as it will reset the player's attributes, without re-loading windowDimensions or Textures.*/
void Player::SetPlayer(int extNumOfLifes)
{
	numOfLives = extNumOfLifes;		//Sets Player::numOfLives to the number of lives passed into this function.
	score = 0;						//Sets the starting score to 0.

	/*Initialises the PlayerStats strings so they can be loaded onto the UI
	before any of them have actually been modified by a collision.*/
	playerStats.resize(2);
	playerStats[0] = "Score: " + std::to_string(score) + "/" + std::to_string(scoreToWin);
	playerStats[1] = "Lives: " + std::to_string(numOfLives);

	/*Sets the starting position to be the bottom of the screen no matter the resolution*/
	sprite.setScale((windowDimensions.x * 0.00175f), (windowDimensions.y * 0.00234f));
	sprite.setPosition((windowDimensions.x / 2), (windowDimensions.y * 1.0f));
}

/*This is the collision function, it will take 3 values, the vehicles, the ending zone and the level bounds.
If the player's bounds intersect with either of the objects bounds, it will register as
a collision and an action relative to that collision can be carried out.*/
void Player::Collision(std::vector<sf::Sprite> vehicles, sf::RectangleShape levelEnd, std::vector<sf::RectangleShape> levelBounds)
{
	/*Check if the player has collided with any of the vehicles.*/
	for (int i = 0; i < vehicles.size(); i++)
	{
		if (sprite.getGlobalBounds().intersects(vehicles[i].getGlobalBounds()))
		{
			std::cout << "Player's Lives: " << numOfLives << std::endl;

			sprite.setPosition((windowDimensions.x / 2), (windowDimensions.y * 1));	//Reset the player's position.

			numOfLives--;	//Player loses a life.

			playerStats[1] = "Lives: " + std::to_string(numOfLives); //Update the numOfLives string so that it can be displayed via the UI.
		}
		else if (sprite.getGlobalBounds().intersects(levelEnd.getGlobalBounds()))
		{
			std::cout << "Player score is: " << score << std::endl;

			sprite.setPosition((windowDimensions.x / 2), (windowDimensions.y * 1));	//Reset the player's position.

			score++;	//Player gains a point.

			playerStats[0] = "Score: " + std::to_string(score) + "/" + std::to_string(scoreToWin);	//Update the score string so that it can be displayed via the UI.

			sprite.scale(scalingValue);	//Each time player scores a point, increase the player's size to make it more difficult.
		}

		/*Checks if the player is colliding with any of the level bounds and will move the player
		slightly in the opposite direction to the level bound so as to stop them from ever being able to
		exit the level.*/
		for (int i = 0; i < levelBounds.size(); i++)
		{
			if (sprite.getGlobalBounds().intersects(levelBounds[i].getGlobalBounds()))
			{
				switch (i)
				{
				case 0:
					sprite.move(-5.0f, 0);
					break;
				case 1:
					sprite.move(0, -5.0f);
					break;
				case 2:
					sprite.move(5.0f, 0);
					break;
				}
			}
		}
	}
}

/*Returns the player's stats (lives, score) as strings so that they can be passed into the 
UI class to create the HUD.*/
std::vector<sf::String> Player::getStats()
{
	return playerStats;
}

/*Checks for relevant keyboard input via the sf::Event and then moves this current object's sprite by
movementSpeed accordingly. Avoids constant movement by setting the isKeyDown boolean to false when a key is
released and to true when a key is pressed and the initial movement has been carried out.*/
void Player::Movement(sf::Event event, bool gameHasFocus)
{
	if (gameHasFocus)
	{
		if (event.type == sf::Event::KeyPressed && isKeyDown == false)
		{
			if (event.key.code == sf::Keyboard::Up)
			{
				sprite.move(0, -movementSpeedY);
				sprite.setRotation(0);
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				sprite.move(0, movementSpeedY);
				sprite.setRotation(180);
			}
			else if (event.key.code == sf::Keyboard::Left)
			{
				sprite.move(-movementSpeedX, 0);
				sprite.setRotation(270);
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				sprite.move(movementSpeedX, 0);
				sprite.setRotation(90);
			}

			isKeyDown = true;
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			isKeyDown = false;
		}
	}
}

/*Can be called and will return true if the player has 0 lifes.*/
bool Player::isDead()
{
	return (numOfLives <= 0);
}
/*Can be called and will return true if the player has scored as many
points as is needed to win. (scoreToWin value in InstantiatePlayer())*/
bool Player::hasWon()
{
	return (score >= scoreToWin);
}

/*Returns the player's sprite when called. Do not allow externally setting the sprite.*/
sf::Sprite Player::getSprite()
{
	return sprite;
}
