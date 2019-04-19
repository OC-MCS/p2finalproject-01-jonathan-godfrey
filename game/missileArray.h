#pragma once
#include "missile.h"
#include <list>
#include <SFML\Graphics.hpp>

class MissileArray {
private:
	list<Missile> missiles;
	Texture missileTexture;
	int missileCount = 0;

public:
	//MissileArray();
	MissileArray(Texture& misTexture);
	void addMissile(float shipX, float shipY);
	list<Missile>::iterator removeMissile(list<Missile>::iterator it);
	void updateMissiles(RenderWindow& window);
	list<Missile>& getMissileArray();

};