#include "UI.h"

void UI::InitializeUI(sf::Vector2f windowDimensions, sf::String fontName) 
{
	//04b30.ttf
	font.loadFromFile("resources/fonts/" + fontName);
	WindowDimensions = windowDimensions;
}
UI::UI()
{
	
}
UI::~UI()
{
}

void UI::CreateHUD(std::vector<sf::String> elements, int textSize, sf::RenderWindow *window)
{
	float xPos;
	std::vector<sf::Text> textElements;
	textElements.resize(elements.size());

	for (int i = 0; i < textElements.size(); i++)
	{
		switch (i)
		{
		case 0:
			xPos = 0.8f;
			break;
		case 1:
			xPos = 0.02f;
			break;
		}

		textElements[i] = sf::Text(elements[i], font, textSize);
		textElements[i].setPosition((WindowDimensions.x * xPos), (WindowDimensions.y * 0.02f));

		window->draw(textElements[i]);
	}
}

/*TEMPORARY PASSING OF *WINDOW*/
int UI::CreatePanel(sf::String panelTitle, std::vector<sf::String> buttonNames, sf::RenderWindow *window)
{
	float yPos;

	sf::Text title(panelTitle, font, 32);
	title.setPosition((WindowDimensions.x * 0.42f), (WindowDimensions.y * 0.2f));

	std::vector<sf::RectangleShape> buttons;
	std::vector<sf::Text> buttonText;
	buttons.resize(buttonNames.size());
	buttonText.resize(buttons.size());
	
	for (int i = 0; i < buttonNames.size(); i++)
	{
		switch (i)
		{
		case 0:
			yPos = 0.3f;
			break;
		case 1:
			yPos = 0.5f;
			break;
		case 2:
			yPos = 0.7f;
			break;
		default:
			yPos = 0.9f;
		}

		buttons[i] = sf::RectangleShape(sf::Vector2f(140, 40));
		buttons[i].setPosition((WindowDimensions.x * 0.45f), (WindowDimensions.y * yPos));

		buttonText[i] = sf::Text(buttonNames[i], font, 24);
		buttonText[i].setPosition((WindowDimensions.x * 0.47f), (WindowDimensions.y * (yPos + 0.01f)));
		buttonText[i].setColor(sf::Color::Black);

		window->draw(title);
		window->draw(buttons[i]);
		window->draw(buttonText[i]);
	}

	sf::RectangleShape mouseRect(sf::Vector2f(20, 20));
	mouseRect.setPosition(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

	for (int i = 0; i < buttons.size(); i++)
	{
		if (mouseRect.getGlobalBounds().intersects(buttons[i].getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			return i;
		}
	}
	
}
