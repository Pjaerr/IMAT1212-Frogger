#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class UI
{
private:
	//Components
	sf::Font font;					//the font passed in when initialized.				
	sf::Vector2f WindowDimensions;	//The window dimensions passed in when Initialized.

public:
	int CreatePanel(sf::String panelTitle, std::vector<sf::String> buttonNames, sf::RenderWindow *window);
	void CreateHUD(std::vector<sf::String> elements, int textSize, sf::RenderWindow *window);
	void InitializeUI(sf::Vector2f windowDimensions, sf::String fontName);
	UI();
	~UI();
};

