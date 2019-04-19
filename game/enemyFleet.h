#pragma once
#include "enemy.h"
#include "bombArray.h"
#include "gameMgr.h"
#include <list>

class EnemyFleet {
private: 
	list<Enemy> enemies;

	const int BOMB_TIMER = 60;
	int timer;

public: 
	EnemyFleet();		// Default constructor
	void createEnemies(Texture& enemyText);
	void checkIfEnemyHit(MissileArray& missiles, GameMgr& mgr);		// Checks each enemy in list if they were hit with missile
	bool checkCollision(GameMgr& mgr, Texture& enemyText);		// Checks if enemies collide with ship and decrements life
	void updateEnemies(RenderWindow& window, BombArray& bombs, int level);		// Moves all enemies in list down screen and keeps track of bomb timer
	void dropBombs(BombArray& bombs);	// Drops bomb from random enemy

};