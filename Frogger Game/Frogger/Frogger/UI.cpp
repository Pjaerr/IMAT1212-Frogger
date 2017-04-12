#include "UI.h"

/*Called to give the UI class a font and the dimensions of the window (for scaling).
fontName takes a file and an extension (font.ttf), fonts must be stored in ../resources/fonts/*/
void UI::InitializeUI(sf::Vector2f windowDimensions, sf::String fontName) 
{
	//04b30.ttf from DaFont.com.
	font.loadFromFile("resources/fonts/" + fontName);
	WindowDimensions = windowDimensions;
	textSize = (int)(WindowDimensions.y * 0.02f); //Makes sure that the size of text scales to the resolution.
}

UI::UI()
{
	
}
UI::~UI()
{
}

/*Takes the strings passed in and assigns them to sf::Text elements that are then sized, placed
and drawn onto the screen. The xPosition of the Text elements are decided by their order. First element
goes onto the far left, second far right etc.*/
void UI::CreateHUD(std::vector<sf::String> elements, sf::RenderWindow *window)
{
	float xPos;	//The position on which the elements will be placed.

	std::vector<sf::Text> textElements;	//The vector containing the sf::Text elements.
	textElements.resize(elements.size());

	for (int i = 0; i < textElements.size(); i++)
	{
		switch (i)
		{
		case 0:
			xPos = 0.8f;	//Set position to far right of the screen (80%).
			break;
		case 1:
			xPos = 0.02f;	//Set position to far left of the screen (2%).
			break;
		}
		
		/*Sets the sf::Text vector's values to the sf::String vector that was passed in and then
		positions the text elements.*/
		textElements[i] = sf::Text(elements[i], font, textSize);
		textElements[i].setPosition((WindowDimensions.x * xPos), (WindowDimensions.y * 0.02f));

		window->draw(textElements[i]);
	}
}

/*This function creates a panel style UI. Title > Button > Button etc. It takes a panel title, and then
the names of each button in the order they should be placed. It takes the button names, and creates buttons
using the string. Each button is placed the same width apart. It will then draw the title and the buttons.
Lastly, it will return the number of the button that is currently being clicked so that an action can be
assigned in the place where the function is called.*/
int UI::CreatePanel(sf::String panelTitle, std::vector<sf::String> buttonNames, sf::RenderWindow *window)
{
	float yPos;	//The position on which the elements will be placed.

	sf::Text title(panelTitle, font, (textSize + 8));											//Sets the title to the string passed in.
	title.setPosition((WindowDimensions.x * 0.42f), (WindowDimensions.y * 0.2f));	//Sets the position of the title to be the top center.	

	std::vector<sf::RectangleShape> buttons;	//Creates vector of rectangles, used as buttons.
	buttons.resize(buttonNames.size());			//Sizes it to the number of button names passed in.

	std::vector<sf::Text> buttonText;			//Creates the text for those buttons.
	buttonText.resize(buttons.size());			//Sizes it to the amount of buttons that exist.
	
	for (int i = 0; i < buttonNames.size(); i++)
	{
		switch (i)
		{
		case 0:
			yPos = 0.3f;	//Sets y position to 1 space below the title.
			break;
		case 1:
			yPos = 0.5f;	//Sets y position to 2 spaces below the first button.
			break;
		case 2:
			yPos = 0.7f;
			break;
		default:
			yPos = 0.9f;
		}


		
		/*Sets the button's size and position.*/
		buttons[i] = sf::RectangleShape(sf::Vector2f((WindowDimensions.x * 0.1f), (WindowDimensions.y * 0.04f)));
		buttons[i].setPosition((WindowDimensions.x * 0.45f), (WindowDimensions.y * yPos));

		/*Initialises the text to the strings passed in and positions it on top of the buttons.*/
		buttonText[i] = sf::Text(buttonNames[i], font, textSize);
		buttonText[i].setPosition((WindowDimensions.x * 0.47f), (WindowDimensions.y * (yPos + 0.01f)));
		buttonText[i].setColor(sf::Color::Black);

		/*Drawing all relevant objects.*/
		window->draw(title);
		window->draw(buttons[i]);
		window->draw(buttonText[i]);
	}

	/*Creates a FloatRect that follows the mouse around, then checks if the FloatRect is intersecting with a button and if the mouse
	is left clicking. If those values are true, this function will return the number (in order of the buttonNames passed in) of the
	button that has been clicked, allowing actions to be carried out, outside of the UI class.*/
	sf::FloatRect mouseRect(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y, 20, 20);
	//mouseRect.setPosition(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

	for (int i = 0; i < buttons.size(); i++)
	{
		if (mouseRect.intersects(buttons[i].getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			return i;
		}
	}
	
}
