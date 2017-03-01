#include "Player.h"

/*Checks for relevant keyboard input and then moves this current object's sprite accordingly.*/
void Player::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sprite.move(0, (-0.01f * movementSpeed));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sprite.move((-0.01f * movementSpeed), 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sprite.move((0.01f * movementSpeed), 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sprite.move(0, (0.01f * movementSpeed));
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
	
	sprite.setPosition(280, 380); //Placeholder setting starting pos.

}

/*The default constructor will set the player attributes by default.*/
Player::Player()
{
	movementSpeed = 5;
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
