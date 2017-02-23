#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Game
{
private:

public:
	void RenderGame();
	void EventHandling(sf::RenderWindow& window);
	void StartGame();
	Game();
	~Game();
};

