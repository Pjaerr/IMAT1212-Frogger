#pragma once

#include "Player.h"
#include "Vehicle.h"

class Game
{
private:
	sf::Texture levelTexture;
	sf::Sprite level;
	Player player;
	Vehicle vehicle;
	void EventHandling(sf::RenderWindow& window);
	void RenderGame();
	void InitializeLevel();

public:
	void StartGame();
	Game();
	~Game();
};
