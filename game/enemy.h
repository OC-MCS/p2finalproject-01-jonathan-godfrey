#pragma once
#include "missileArray.h"
#include "bombArray.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf; 

class Enemy {
private:
	Sprite enemySprite;

public:
	Enemy(Texture& enemyText, float enemyX, float enemyY);	// Constructor: sets texture to sprite
	void move(int level);	// Moves enemy
	void dropBomb(BombArray& bombs);	// drops a bomb from position of enemy
	bool isEnemyHit(MissileArray &missileArray);	// checks if enemy was hit by missile
	Sprite getSprite();		// returns enemySprite
	Vector2f getPosition(); // Returns vector of enemySprite's position
};