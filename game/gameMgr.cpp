#include "gameMgr.h"

GameMgr::GameMgr(RenderWindow& window)
{
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
		cout << "Unable to load menu font!" << endl;
		exit(EXIT_FAILURE);
	}

	Vector2f size(window.getSize().x / 3.0f, window.getSize().y / 4.0f);
	Vector2f pos((window.getSize().x - size.x) / 2.0f, (window.getSize().y - size.y) / 2.0f);
	startBtn.setPosition(pos);
	startBtn.setSize(size);
	startBtn.setFillColor(Color::Blue);
	score = 0;
	lives = 3;
	level = 0;
}

void GameMgr::drawStartMenu(RenderWindow &window) 
{
	Text text("START", font, 50);
	text.setFillColor(Color::White);
	text.setPosition(startBtn.getPosition().x + (startBtn.getSize().x - text.getLocalBounds().width) / 2, 
		startBtn.getPosition().y + startBtn.getSize().y / 2 - text.getLocalBounds().height);
	window.draw(startBtn);
	window.draw(text);

	text.setFont(font);
	text.setFillColor(Color(255, 255, 255));

	text.setString("Space Invaders");
	text.setCharacterSize(60);
	text.setPosition(190, 100);
	window.draw(text);
};

void GameMgr::loseLife()
{
	lives--;
	if (lives < 1)
		gameLost = true;
}

void GameMgr::resetScore(int level)
{
	if (level == 1)
		score = 0;
	else if (level == 2)
		score = 10;
}

void GameMgr::displayData(RenderWindow &window) 
{
	text.setFont(font);
	text.setString("Lives: " + to_string(lives) + "   Level: " + to_string(level) + "   Aliens killed: " + to_string(score));
	text.setFillColor(Color(255, 255, 255));
	text.setCharacterSize(24);
	text.setPosition(8, 0);
	window.draw(text);
};

bool GameMgr::isButtonPressed(Vector2f pos)
{
	if (startBtn.getGlobalBounds().contains(pos)) 
	{
		startPressed = true;
	}
	return startPressed;
}

int GameMgr::getLives()
{
	return lives;
}

int GameMgr::getScore()
{
	return score;
}

void GameMgr::enemyKilled()
{
	score++;
}

void GameMgr::win(RenderWindow& window)
{
	Text title2("You Won!", font, 50);
	title2.setFillColor(Color::White);
	title2.setPosition(startBtn.getPosition().x + (startBtn.getSize().x - startBtn.getLocalBounds().width) / 2, 20);
	window.draw(title2);
}

void GameMgr::lose(RenderWindow& window)
{
	Text title2("You Lose!", font, 50);
	title2.setFillColor(Color::White);
	title2.setPosition(startBtn.getPosition().x + (startBtn.getSize().x - startBtn.getLocalBounds().width) / 2, 20);
}