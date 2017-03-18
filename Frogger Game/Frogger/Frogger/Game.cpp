#include "Game.h"

Game::Game()
{
	InitializeLevel();
}
Game::~Game()
{
	window->~RenderWindow();	//Deallocates the memory given to the RenderWindow *window object.
}

/*This is the method used to render any game objects. This can be from within the Game class or outside of it.
Event handling is called inside of this method for continuity's sake and to avoid passing around the main RenderWindow
object. If something is to effect the window that isn't a specific event, it will go inside of this method.*/
void Game::RenderGame()
{
	/*Assigning a value to the RenderWindow *window pointer created in the header file.*/
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Frogger");
																			
	/*The Game loop used for rendering. Anything that fits within rendering	goes here.
	Mainly drawing.It is the main game loop, but anything other than rendering can be placed in external methods.*/
	while (window->isOpen())
	{
		window->clear(sf::Color::Black);
		
		window->draw(level);					
		window->draw(player.getSprite());	//Draws the returned sprite from the player.

		/*Draws all of the vehicle's sprites from the Sprite[] array.*/
		for (int i = 0; i < vehicle.getSprite().size(); i++)	
		{
			window->draw(vehicle.getSprite()[i]);	
		}
		
		window->display();

		EventHandling();	//Handles any events both internal and external once drawing has been completed.
	}
	
}

/*Any events not specific to rendering go inside of the EventHandling method.
Try to keep events inside their own methods and only called from here.*/
void Game::EventHandling()
{										
	sf::Event event;
	while (window->pollEvent(event))			//Checks if any events have occured on the window, if they have they will be pushed to the top of the event queue.
	{
		if (event.type == sf::Event::Closed)	//Checks to see if the closed event has been triggered on the window and closes the window if so.
		{
			window->close();
		}
	}

	player.Movement(event);		//Tells the Player to move itself using a copy of the sf::Event object.
	vehicle.Movement(100.0f);	//Tells the Vehicle to move its sprites. Will occur every loop.
}

void Game::StartGame()
{
	RenderGame();
}

void Game::InitializeLevel()
{
	if (!levelTexture.loadFromFile("resources/levelTextureNew.png"))
	{
	}
	else
	{
		/*Sets the texture for the level initially and saves the window dimensions to a Vector2.
		Scales the newly textured sprite to fit the aforementioned Vector2. This results in
		the level sprite being the same size as the window, if the window changes these values
		can be tweaked and the level object will scale nicely.*/
		level.setTexture(levelTexture);
		sf::Vector2f windowDimensions(640.0f, 480.0f);
		level.setScale(windowDimensions.x / level.getLocalBounds().width, windowDimensions.y / level.getLocalBounds().height);
	}
}
