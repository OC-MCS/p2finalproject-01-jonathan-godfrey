#include "bombArray.h"

BombArray::BombArray(Texture& bomTexture)
{
	bombTexture = bomTexture;
}

void BombArray::addBomb(float enemyX, float enemyY)
{
	Bomb bom(bombTexture, enemyX + 8, enemyY+16);
	bombs.push_back(bom);
}

list<Bomb>::iterator BombArray::removeBomb(list<Bomb>::iterator it)
{
	list<Bomb>::iterator iter;
	iter = bombs.erase(it);
	return iter;
}

void BombArray::updateBombs(RenderWindow& window, int level)
{
	list<Bomb>::iterator iter;

	for (iter = bombs.begin(); iter != bombs.end(); iter++)
		iter->move(level);
	for (iter = bombs.begin(); iter != bombs.end();)
	{
		window.draw(iter->getSprite());
		if (iter->getPosition().y < 0)
			iter = bombs.erase(iter);
		else
			iter++;
	}
}

list<Bomb>& BombArray::getBombArray()
{
	return bombs;
}
