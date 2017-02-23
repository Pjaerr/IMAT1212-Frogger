#include "Player.h"

void Player::Movement()
{
	/*Checks for relevant keyboard input and then moves this current object's sprite
	accordingly.*/
}

void Player::PlayerInstantiation()
{
	//Assign texture to player sprite in here.
}

Player::Player(float movementSpeed, int numOfLives)
{
	/*Sets the player's default attributes on player object construction.*/
	Player::movementSpeed = movementSpeed || 5;
	Player::numOfLives = numOfLives || 3;
	PlayerInstantiation();
}

Player::~Player()
{
}
