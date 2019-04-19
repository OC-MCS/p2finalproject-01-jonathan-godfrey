#include "enemy.h"
#include <iostream>

Enemy::Enemy(Texture& enemyText, float enemyX, float enemyY)
{
	enemySprite.setTexture(enemyText);
	enemySprite.setScale(0.8, 0.8);
	enemySprite.setPosition(enemyX, enemyY);
}

// Moves enemies down at different speed depending on level
void Enemy::move(int level)
{
	if (level == 1)
		enemySprite.move(0, 0.2f);
	else if (level == 2)
		enemySprite.move(0, 0.4f);
}

// Drops bombs at enemy position
void Enemy::dropBomb(BombArray& bombs)
{
	bombs.addBomb(enemySprite.getPosition().x + 20, enemySprite.getPosition().y+48);
}

// checks if enemy is hit and deletes enemy and missile
bool Enemy::isEnemyHit(MissileArray &missiles)
{
	bool hit = false;
	//FloatRect missileBounds; //= missile.getSprite().getGlobalBounds();
	FloatRect enemyBounds = enemySprite.getGlobalBounds();
	list<Missile>::iterator iter;
	
	iter = missiles.getMissileArray().begin();
	while (iter != missiles.getMissileArray().end()) 
	{
		if (enemyBounds.intersects(iter->getBounds())) 
		{
			iter = missiles.removeMissile(iter);	// delete the missile
			hit = true;
		}
		else {
			iter++;
		}
	}
	return hit;
}

// getter function returns enemySprite
Sprite Enemy::getSprite()
{
	return enemySprite;
}

// getter function returns enemySprite position
Vector2f Enemy::getPosition()
{
	return enemySprite.getPosition();
}