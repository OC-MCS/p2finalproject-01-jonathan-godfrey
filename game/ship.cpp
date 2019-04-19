#include "ship.h"

Ship::Ship(Texture& shipTexture, float x, float y)
{
	shipSprite.setTexture(shipTexture);
	shipSprite.setPosition(x, y);
}

void Ship::move()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		if (shipSprite.getPosition().x > 0)
			shipSprite.move(-DISTANCE, 0);

	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		if (shipSprite.getPosition().x < 780)
			shipSprite.move(DISTANCE, 0);
	}
}

void Ship::updateShip(RenderWindow& window)
{
	window.draw(shipSprite);
}


bool Ship::isShipHit(BombArray& bombs, GameMgr& mgr)
{
	bool hit = false;
	list<Bomb>::iterator bombIter;
	bombIter = bombs.getBombArray().begin();
	while (bombIter != bombs.getBombArray().end()) 
	{
		if (getBounds().contains(bombIter->getPosition())) 
		{
			bombIter = bombs.getBombArray().erase(bombIter); // delete the bomb
			mgr.loseLife();		  // remove a life from the ship
			hit = true;
		}
		else 
			bombIter++;
	}
	return hit;
}

Sprite Ship::getSprite()
{
	return shipSprite;
}

void Ship::launchMissile(MissileArray& missiles)
{
	missiles.addMissile(getPosition().x, getPosition().y);
}

Vector2f Ship::getPosition()
{
	return shipSprite.getPosition();
}

FloatRect Ship::getBounds()
{
	FloatRect shipBounds = shipSprite.getGlobalBounds();
	return shipBounds;
}