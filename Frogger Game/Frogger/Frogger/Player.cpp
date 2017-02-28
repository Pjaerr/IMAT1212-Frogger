#include "Player.h"

void Player::Movement()
{
	/*Checks for relevant keyboard input and then moves this current object's sprite
	accordingly.*/
}

void Player::PlayerInstantiation()
{
	if (!texture.loadFromFile("resources/frogTexture.png"))
	{
	}
	else
	{
		sprite.setTexture(Player::texture);
	}
	
}

Player::Player()
{
	movementSpeed = 5;
	numOfLives = 3;
	PlayerInstantiation();
}
Player::Player(float movementSpeed, int numOfLives)
{
	Player::movementSpeed = movementSpeed;
	Player::numOfLives = numOfLives;
	PlayerInstantiation();
}

Player::~Player()
{
}
