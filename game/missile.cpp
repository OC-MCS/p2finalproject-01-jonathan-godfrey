#include "missile.h"
#include "ship.h"

Missile::Missile(Texture& missileTexture, float x, float y)
{
	missileSprite.setTexture(missileTexture);
	missileSprite.setScale(0.3, 0.3);
	missileSprite.setPosition(x+16, y-20);
}

void Missile::move()
{
	missileSprite.move(0, -10);
}

Vector2f Missile::getPosition()
{
	return missileSprite.getPosition();
}

Sprite& Missile::getSprite()
{
	return missileSprite;
}

FloatRect Missile::getBounds()
{
	FloatRect missileBounds = missileSprite.getGlobalBounds();
	return missileBounds;
}