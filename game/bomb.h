#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Bomb {
private:
	Sprite bombSprite;

public:
	Bomb(Texture& bombSprite, float x, float y);
	void move(int level);

	Vector2f getPosition();
	Sprite& getSprite();
	FloatRect getBounds();
};