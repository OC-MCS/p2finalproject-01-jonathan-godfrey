#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Missile {
private:
	Sprite missileSprite;

public:
	Missile(Texture& missileTexture, float x, float y);
	void move();

	Vector2f getPosition();
	Sprite& getSprite();
	FloatRect getBounds();
};