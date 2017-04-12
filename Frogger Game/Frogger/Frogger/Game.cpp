#include "Game.h"

Game::Game()
{
	InitializeGame();
}
Game::~Game()
{
	window->~RenderWindow();	//Deallocates the memory given to the RenderWindow *window object.
}

/*This function uses the UI::CreatePanel() function and passes in Start and Quit buttons.*/
void Game::MainMenu()
{
	std::vector<sf::String> buttonNames;
	buttonNames.resize(2);

	buttonNames[0] = "Start";
	buttonNames[1] = "Quit";


	int buttonPressed = ui.CreatePanel("Frogger!", buttonNames, window);	//See UI::CreatePanel()

	/*If the first button is clicked, start the Play game state and turn off the main menu.
	If the second button is clicked, close the window.*/
	switch (buttonPressed)
	{
	case 0:
		GameState_MainMenu = false;
		GameState_Play = true;
		break;
	case 1:
		window->close();
		break;
	}
	
}


/*This is the method used to render any game objects. This can be from within the Game class or outside of it.
Event handling is called inside of this method for continuity's sake and to avoid passing around the main RenderWindow
object. If something is to effect the window that isn't a specific event, it will go inside of this method.*/
void Game::RenderGame()
{
	/*Assigning a value to the RenderWindow *window pointer created in the header file.*/
	window = new sf::RenderWindow(sf::VideoMode(windowDimensions.x, windowDimensions.y), "Frogger");

	/*The Game loop used for rendering. Anything that fits within rendering	goes here.
	Mainly drawing.It is the main game loop, but anything other than rendering can be placed in external methods.*/
	while (window->isOpen())
	{
		window->clear(sf::Color::Black);

		if (GameState_MainMenu) //If the game state is currently Main Menu.
		{
			//gameHasFocus = false;
			MainMenu();
		}
		else if (GameState_Play)	//If the Main menu has been exited, and the game state is currently Play.
		{

			window->draw(level);				//Draws the level sprite from Game.h
			window->draw(player.getSprite());	//Draws the returned sprite from the player.
				
			/*Draws a HUD created using the UI::CreateHUD method. It passes in the
			player's stats (as a vector), the font size 20 and the window*/
			ui.CreateHUD(player.getStats(), window); 

			/*Draws all of the vehicle's sprites from the Sprite[] array.*/
			for (int i = 0; i < vehicle.getSprite().size(); i++)
			{
				window->draw(vehicle.getSprite()[i]);
			}
		}
		else if (GameState_EndDeath)	//If the player has died and the Game state End is active.
		{
			GameEnd("You Lose!");
		}
		else if (GameState_EndWin)	//If the player has died and the Game state End is active.
		{
			GameEnd("You Win!");
		}

		window->display();

		EventHandling();	//Handles any events both internal and external once drawing has been completed.

	}
}

/*Creates a panel UI similar to in the MainMenu() function, passing in the buttons
Replay and Quit. Clicking each will either restart the game or close the window. It takes
a title that will be shown as the title of the ending panel UI.*/
void Game::GameEnd(sf::String title)
{
	gameHasFocus = false;

	std::vector<sf::String> buttonNames;
	buttonNames.resize(2);

	buttonNames[0] = "Replay";
	buttonNames[1] = "Quit";

	int buttonPressed = ui.CreatePanel(title, buttonNames, window);

	switch (buttonPressed)
	{
	case 0:
		RestartGame();
		break;
	case 1:
		window->close();
		break;
	}
}
	
void Game::RestartGame()
{
	std::cout << "Game restarted!" << std::endl;
	player.SetPlayer(3);	//Resets the player's positional, size, and statistical values. Passing in 3 lives.
	GameState_EndDeath = false;	//Closes the end game menu.
	GameState_Play = true;	//Restarts the game.
	gameHasFocus = true;
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
		else if (event.type == sf::Event::LostFocus)
		{
			gameHasFocus = false;
			std::cout << "Game doesn't have focus" << std::endl;
		}
		else if (event.type == sf::Event::GainedFocus)
		{
			gameHasFocus = true;
			std::cout << "Game has focus" << std::endl;
		}
	}

	player.Movement(event, gameHasFocus);				//Tells the Player to move itself using a copy of the sf::Event object.
	vehicle.Movement(gameHasFocus);	//Tells the Vehicle to move its sprites and whether or the window has focus. Will occur every loop.

	player.Collision(vehicle.getSprite(), levelEndZone, levelBounds);	//Checks for collision on the player.	

	/*If the player has died, change the game states accordingly.*/
	if (player.isDead())
	{
		GameState_Play = false;
		GameState_EndDeath = true;
	}
	else if (player.hasWon())
	{
		GameState_Play = false;
		GameState_EndWin = true;
	}
}

void Game::StartGame()
{
	RenderGame();
}

void Game::InitializeGame()
{
	/*Initializes the game states.*/
	GameState_MainMenu = true;
	GameState_Play = false;
	GameState_EndDeath = false;
	GameState_EndWin = false;

	windowDimensions = sf::Vector2f(1024, 768);	//Initialises the window dimensions.

	ui.InitializeUI(windowDimensions, "04b30.ttf");			 //Starts the UI class with the font 04b30.ttf and the window dimensions.
	vehicle.InstantiateVehicle(windowDimensions, 24, 4);	 //Starts the vehicle class with 24 sprites, 4 textures and passes in the window dimensions.
	player.InstantiateClass(windowDimensions, 3, 5); //Starts the player class with 45 movement speed, 3 lifes and passes in the window dimensions and scoretoWin.

	if (!levelTexture.loadFromFile("resources/levelTexture.png"))
	{
	}
	else
	{
		/*Sets the texture for the level initially and saves the window dimensions to a Vector2.
		Scales the newly textured sprite to fit the aforementioned Vector2. This results in
		the level sprite being the same size as the window, if the window changes these values
		can be tweaked and the level object will scale nicely.*/
		level.setTexture(levelTexture);
		level.setScale(windowDimensions.x / level.getLocalBounds().width, windowDimensions.y / level.getLocalBounds().height);
	}

	levelEndZone.setSize(sf::Vector2f(windowDimensions.x, (windowDimensions.y * 0.04)));	//Sets end zone to be 4% of the window height.

	levelBounds.resize(3);

	/*Initialises the level bounds thickness, position and size.*/
	for (int i = 0; i < levelBounds.size(); i++)
	{
		levelBounds[i].setOutlineThickness(-2);

		switch (i)
		{
		case 0:
			levelBounds[i].setPosition(sf::Vector2f(windowDimensions.x, 0));
			levelBounds[i].setSize(sf::Vector2f(0, windowDimensions.y));
			break;
		case 1:
			levelBounds[i].setPosition(sf::Vector2f(0, windowDimensions.y));
			levelBounds[i].setSize(sf::Vector2f(windowDimensions.x, 0));
			break;
		case 2:
			levelBounds[i].setPosition(sf::Vector2f(0, 0));
			levelBounds[i].setSize(sf::Vector2f(0, windowDimensions.y));
			break;
		}
	}
}
