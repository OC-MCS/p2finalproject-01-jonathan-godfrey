#include "enemyFleet.h"
#include <stdlib.h>     
#include <time.h>

// Constructor
EnemyFleet::EnemyFleet()
{

}

// Spawns 10 enemies across screen
void EnemyFleet::createEnemies(Texture& enemyText)
{
	list<Enemy>::iterator iter;
	iter = enemies.begin();
	while (iter != enemies.end())
	{
		iter = enemies.erase(iter);
	}

	for (int i = 0; i < 10; i++)
	{
		Enemy en(enemyText, 60.0f + (70.0f * i), 50.0f);
		enemies.push_back(en);
	}
}

// Checks if an enemy was hit by a missile and deletes both enemy and missile.
void EnemyFleet::checkIfEnemyHit(MissileArray& missiles, GameMgr& mgr)
{
	list<Enemy>::iterator iter;
	iter = enemies.begin();
	while (iter != enemies.end()) 
	{
		if (iter->isEnemyHit(missiles)) 
		{
			iter = enemies.erase(iter); 
			mgr.enemyKilled(); 
		}
		else {
			iter++;
		}
	}
}

// Checks if enemies have reached the ship and decreases lives of player
bool EnemyFleet::checkCollision(GameMgr& mgr, Texture& enemyText)
{
	list<Enemy>::iterator iter;
	if (!enemies.empty())
	{
		iter = enemies.begin();
		if (iter->getPosition().y > 500)
			return true;
		else
			return false;
	}
	
}

// Moves enemies down screen at different speeds depending on level
// Also runs dropBombs to update timer and drops bombs when timer runs out
void EnemyFleet::updateEnemies(RenderWindow& window, BombArray& bombs, int level)
{
	list<Enemy>::iterator iter;
	iter = enemies.begin();

	// steps through linked list and moves each enemy
	if (level == 1)
	{
		while (iter != enemies.end())  
		{
			iter->move(level);
			window.draw(iter->getSprite());
			iter++;
		}
	}
	else if (level == 2)
	{
		while (iter != enemies.end())
		{
			iter->move(level);
			window.draw(iter->getSprite());
			iter++;
		}
	}

	dropBombs(bombs);
}

// Keeps track of timer to drop bombs
// Picks random enemy to drop bomb when timer runs out
void EnemyFleet::dropBombs(BombArray& bombs)
{
	// If timer runs out, drop bomb and reset timer
	if (timer > 0)
	{
		timer--;
	}
	else
	{
		if (!enemies.empty())
		{
			list<Enemy>::iterator iter = enemies.begin();
			int num;
			srand(time(0));
			num = (rand() % enemies.size());

			advance(iter, num);
			iter->dropBomb(bombs);

			timer = BOMB_TIMER;
		}
	}
	
}