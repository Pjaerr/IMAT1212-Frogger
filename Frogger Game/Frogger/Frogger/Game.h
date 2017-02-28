#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"

class Game
{
private:
	sf::Texture levelTexture;
	sf::Sprite level;
	Player player;
	void EventHandling(sf::RenderWindow& window);
	void RenderGame();
	void InitializeLevel();

public:
	void StartGame();
	Game();
	~Game();
};

