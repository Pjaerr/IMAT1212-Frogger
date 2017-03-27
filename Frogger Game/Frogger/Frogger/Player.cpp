#include "Player.h"

/*The default constructor will set the player attributes by default.*/
Player::Player()
{
}
Player::~Player()
{
}

/*This is the collision function, it will take 3 values, the vehicles, the ending zone and the level bounds.
If the player's bounds intersect with either of the objects bounds, it will register as
a collision and an action relative to that collision can be carried out.*/
void Player::Collision(std::vector<sf::Sprite> vehicles, sf::RectangleShape levelEnd, std::vector<sf::RectangleShape> levelBounds)
{
	for (int i = 0; i < vehicles.size(); i++)
	{
		if (sprite.getGlobalBounds().intersects(vehicles[i].getGlobalBounds()))
		{
			std::cout << "Player's Lives: " << numOfLives << std::endl;

			sprite.setPosition((windowDimensions.x / 2), (windowDimensions.y * 0.92));	//Reset the player's position.

			numOfLives--;	//Player loses a life.

			if (isDead())
			{
				//Player has died.
			}
		}
		else if (sprite.getGlobalBounds().intersects(levelEnd.getGlobalBounds()))
		{
			std::cout << "Player scores 1 point" << std::endl;

			sprite.setPosition((windowDimensions.x / 2), (windowDimensions.y * 0.92));	//Reset the player's position.

			score++;	//Player gains a point.

			if (score >= 5)
			{
				//Player Wins
			}
			sprite.scale(1.1f, 1.1f);	//Each time player scores a point, increase the player's size to make it more difficult.
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

/*Checks for relevant keyboard input via the sf::Event and then moves this current object's sprite by
movementSpeed accordingly. Avoids constant movement by setting the isKeyDown boolean to false when a key is
released and to true when a key is pressed and the initial movement has been carried out.*/
void Player::Movement(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed && isKeyDown == false)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			sprite.move(0, -movementSpeed);
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			sprite.move(0, movementSpeed);
		}
		else if (event.key.code == sf::Keyboard::Left)
		{
			sprite.move(-movementSpeed, 0);
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
			sprite.move(movementSpeed, 0);
		}

		isKeyDown = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		isKeyDown = false;
	}
}

/*Can be called and will return true if the player has 0 lifes.*/
bool Player::isDead()
{
	return (numOfLives <= 0);
}

/*Returns the player's sprite when called. Do not allow externally setting the sprite.*/
sf::Sprite Player::getSprite()
{
	return sprite;
}

/*Initializes the player's visual attributes.*/
void Player::InstantiatePlayer(sf::Vector2f extWindowDimensions, float extMovementSpeed, int extNumOfLifes)
{
	windowDimensions = extWindowDimensions;
	movementSpeed = extMovementSpeed;
	numOfLives = extNumOfLifes;
	
	if (!texture.loadFromFile("resources/frogTexture.png"))
	{
	}
	else
	{
		sprite.setTexture(texture);
	}

	/*Sets the starting position to be the bottom of the screen no matter the resolution*/
	sprite.setScale(1.8f, 1.8f);
	sprite.setPosition((windowDimensions.x / 2), (windowDimensions.y * 0.92));
}
