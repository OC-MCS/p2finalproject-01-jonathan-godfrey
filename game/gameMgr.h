//====================================================================
// Jonathan Godfrey
// Due April 18th, 2019
// Programming 2 Final Project
// Description: gameMgr Class Definition
//====================================================================
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;

//====================================================================
// The GameManager keeps up with lives and levels along with the menu
// and things relating to the game win and game over state. 
class GameMgr {
private:
	int level = 0; // keeps track of the current level - there is two in total
	int lives = 3; // keeps track of the number of lives remaining for the ship
	int score = 0; // keeps up with the total number of aliens destroyed 

	Text text;
	Font font;
	RectangleShape startBtn;
	bool startPressed = false;
	bool gameLost = false; // set to true when the player is killed
	bool gameWon = false;  // set to true when all aliens are destroyed

public:
	GameMgr(RenderWindow& window);

	void drawStartMenu(RenderWindow &window);	// Displays game title and start button
	
	bool isButtonPressed(Vector2f pos);		// Checks if start button is pressed in menu
	void displayData(RenderWindow &window);	// Displays lives, level, and score on screen

	void loseLife();	// decreases the number of lives the ship has left
	void resetScore(int level);

	int getLives();		// getter functions return information about lives
	int getScore();		// getter functions return information about score

	void enemyKilled();		// increases the total number of aliens killed
	void win(RenderWindow& window);
	void lose(RenderWindow& window);
	
};