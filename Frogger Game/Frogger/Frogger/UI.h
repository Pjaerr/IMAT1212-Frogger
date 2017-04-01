#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class UI
{
private:
	sf::Font font;
	sf::Vector2f WindowDimensions;

public:
	int CreatePanel(sf::String panelTitle, std::vector<sf::String> buttonNames, sf::RenderWindow *window);
	void CreateHUD(std::vector<sf::String> elements, int textSize, sf::RenderWindow *window);
	void InitializeUI(sf::Vector2f windowDimensions, sf::String fontName);
	UI();
	~UI();
};

