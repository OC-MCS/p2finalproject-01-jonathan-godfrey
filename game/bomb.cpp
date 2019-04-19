#include "bomb.h"
#include "enemy.h"

Bomb::Bomb(Texture& bombTexture, float x, float y)
{
	bombSprite.setTexture(bombTexture);
	bombSprite.rotate(180);
	bombSprite.setScale(0.3, 0.3);
	bombSprite.setPosition(x, y);
}

void Bomb::move(int level)
{
	if (level == 1)
		bombSprite.move(0, 10);
	else if (level == 2)
		bombSprite.move(0, 15);
}

Vector2f Bomb::getPosition()
{
	return bombSprite.getPosition();
}

Sprite& Bomb::getSprite()
{
	return bombSprite;
}

FloatRect Bomb::getBounds()
{
	FloatRect bombBounds = bombSprite.getGlobalBounds();
	return bombBounds;
}