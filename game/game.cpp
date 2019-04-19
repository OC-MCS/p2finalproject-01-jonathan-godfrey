//====================================================================
// Jonathan Godfrey
// Due April 18th, 2019
// Programming 2 Final Project
// Description: gameMgr Class Definition
//====================================================================
#include "ship.h"
#include "enemyFleet.h"
#include "gameMgr.h"

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	enum GameState { START, LVL1, LVL2, WIN, LOSE };
	GameState state = START;

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	// Loading Ship Texture
	Texture shipTexture;
	if (!shipTexture.loadFromFile("spaceShip.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// Loading background stars texture
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// Loading Missile texture
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile2.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// Loading Bomb Texture
	Texture bombTexture;
	if (!bombTexture.loadFromFile("bomb.png"))
	{
		cout << "Unable to load bomb texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// Loading Enemy texture
	Texture enemyTexture;
	if (!enemyTexture.loadFromFile("alien.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders!");

	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	GameMgr mgr(window);

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// initial position of the ship will be approx bottom middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.1f;
	MissileArray missiles(missileTexture);
	Ship player(shipTexture, shipX, shipY);

	EnemyFleet enemyFleet;
	enemyFleet.createEnemies(enemyTexture);
	BombArray bombs(bombTexture);

	int count = 0;

	while (window.isOpen())	// graphics loop
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					player.launchMissile(missiles);
				}
			}
		}
		
		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================
		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		if (state == START)
		{
			mgr.drawStartMenu(window);
			// mouse released event: the mouse was clicked most likely on a menu button
			if (event.type == Event::MouseButtonReleased)
			{
				if(mgr.isButtonPressed(window.mapPixelToCoords(Mouse::getPosition(window))))
					state = LVL1;
			}
		}
		else if (state == LVL1)
		{
			//detect key presses to update the position of the ship. 
			player.move();
			player.updateShip(window);

			// Updates enemies
			enemyFleet.updateEnemies(window, bombs, state);
			enemyFleet.checkIfEnemyHit(missiles, mgr);

			// Moves missiles and bombs
			missiles.updateMissiles(window);
			bombs.updateBombs(window, state);

			// Changes game state
			if (player.isShipHit(bombs, mgr) || enemyFleet.checkCollision(mgr, enemyTexture))
			{
				mgr.loseLife();
				enemyFleet.createEnemies(enemyTexture);
				mgr.resetScore(state);
			}
			if (mgr.getScore() == 10)
				state = LVL2;
			else if (mgr.getLives() < 1)
				state = LOSE;

			mgr.displayData(window);
		}
		else if (state == LVL2)
		{  
			if (count == 0)
			{
				enemyFleet.createEnemies(enemyTexture);
				count++;
			}
			//detect key presses to update the position of the ship. 
			player.move();
			player.updateShip(window);

			// updates enemies
			enemyFleet.updateEnemies(window, bombs, state);
			enemyFleet.checkIfEnemyHit(missiles, mgr);

			// Moves missiles and bombs
			missiles.updateMissiles(window);
			bombs.updateBombs(window, state);

			if (player.isShipHit(bombs, mgr) || enemyFleet.checkCollision(mgr, enemyTexture))
			{
				mgr.loseLife();
				enemyFleet.createEnemies(enemyTexture);
				mgr.resetScore(state);
			}

			mgr.displayData(window);

			if (mgr.getScore() == 20)
				state = WIN;
			else if (mgr.getLives() < 1)
				state = LOSE;
		}
		else if (state == WIN)
		{
			mgr.win(window);
		}
		else if (state == LOSE)
		{
			mgr.lose(window);
		}
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

