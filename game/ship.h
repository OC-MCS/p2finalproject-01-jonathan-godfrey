#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "missileArray.h"
#include "bombArray.h"
#include "gameMgr.h"
using namespace std;
using namespace sf;

class Ship {
private:
	Sprite shipSprite;
	const float DISTANCE = 5.0;

public:
	Ship(Texture& shipTexture, float x, float y);
	void move();
	void updateShip(RenderWindow& window);
	void launchMissile(MissileArray& missiles);
	bool isShipHit(BombArray& bombs, GameMgr& mgr);
	
	Sprite getSprite();
	Vector2f getPosition();
	FloatRect getBounds();

};