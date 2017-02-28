#include "Game.h"

/*This is the method used to render any game objects. This can be from within the Game class or outside of it.
Event handling is called inside of this method for continuity's sake and to avoid passing around the main RenderWindow
object. If something is to effect the window that isn't a specific event, it will go inside of this method.*/
void Game::RenderGame()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Frogger");			//Created the Window the game will be rendered to.
													//Calls the EventHandling method and passes in the newly created window.

	while (window.isOpen())													/*The Game loop used for rendering. Anything that fits within rendering																but not within specific sf::Event handling goes here. Mainly drawing.*/
	{
		EventHandling(window);
		window.clear(sf::Color::Black);


		//Draw here.
		window.draw(level);
		window.draw(player.sprite);


		window.display();
	}
}

void Game::EventHandling(sf::RenderWindow& window)
{										
	sf::Event event;
	while (window.pollEvent(event))										/*Checks if any events have occured on the window, if they have they will																		be pushed to the top of the event queue.*/
	{
		if (event.type == sf::Event::Closed)							/*Checks to see if the closed event has been triggered on the window and 
																			closes the window if so.*/
		{
			window.close();
		}
	}
}

void Game::StartGame()
{
	RenderGame();
}

void Game::InitializeLevel()
{
	if (!levelTexture.loadFromFile("resources/levelTexture.png"))
	{
	}
	else
	{
		level.setTexture(Game::levelTexture);
		sf::Vector2f targetSize(640.0f, 480.0f);
		level.setScale(targetSize.x / level.getLocalBounds().width, targetSize.y / level.getLocalBounds().height);
	}
}

Game::Game()
{
	InitializeLevel();
}
Game::~Game()
{
}
