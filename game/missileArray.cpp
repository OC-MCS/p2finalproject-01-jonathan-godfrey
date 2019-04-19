#include "missile.h"
#include "missileArray.h"

MissileArray::MissileArray(Texture& misTexture)
{
	missileTexture = misTexture;
}

void MissileArray::addMissile(float shipX, float shipY)
{
	if (missileCount < 5)
	{
		Missile mis(missileTexture, shipX+8, shipY);
		missiles.push_back(mis);
		missileCount++;
	}
}

list<Missile>::iterator MissileArray::removeMissile(list<Missile>::iterator it)
{
	list<Missile>::iterator iter;
	iter = missiles.erase(it);
	missileCount--;
	return iter;
}

void MissileArray::updateMissiles(RenderWindow& window)
{
	list<Missile>::iterator iter;

	for (iter = missiles.begin(); iter != missiles.end(); iter++)
		iter->move();
	for (iter = missiles.begin(); iter != missiles.end(); /* note no ++ here*/)
	{
		window.draw(iter->getSprite());
		if (iter->getPosition().y < 0)
		{
			iter = missiles.erase(iter);
			missileCount--;
		}
		// the above works because erase returns a new iterator 
		// that points to next thing in list after what we just deleted
		else
			iter++;
	}
}

list<Missile>& MissileArray::getMissileArray()
{
	return missiles;
}
