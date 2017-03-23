#include "Player.h"

/*The default constructor will set the player attributes by default.*/
Player::Player()
{
	movementSpeed = 45.0f;
	numOfLives = 3;
	PlayerInstantiation();
}

/*The alternative constructor allows the person calling to set the player attributes.*/
Player::Player(float movementSpeed, int numOfLives)
{
	Player::movementSpeed = movementSpeed;
	Player::numOfLives = numOfLives;
	PlayerInstantiation();
}

Player::~Player()
{
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

/*Returns the player's sprite when called. Do not allow externally setting the sprite.*/
sf::Sprite Player::getSprite()
{
	return sprite;
}

/*Initializes the player's visual attributes.*/
void Player::PlayerInstantiation()
{
	if (!texture.loadFromFile("resources/frogTexture.png"))
	{
	}
	else
	{
		sprite.setTexture(Player::texture);
	}

	sprite.setPosition(480, 680); //Placeholder setting starting pos.
}
