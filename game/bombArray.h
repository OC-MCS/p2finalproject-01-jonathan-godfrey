#pragma once
#include "bomb.h"
#include <list>
#include <SFML\Graphics.hpp>

class BombArray {
private:
	list<Bomb> bombs;
	Texture bombTexture;

public:
	BombArray(Texture& bomTexture);
	void addBomb(float shipX, float shipY);
	list<Bomb>::iterator removeBomb(list<Bomb>::iterator it);
	void updateBombs(RenderWindow& window, int level);
	list<Bomb>& getBombArray();

};