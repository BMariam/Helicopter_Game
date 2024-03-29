// File: wall.cpp
// Folder: src

#include "gameInit.h"
#include "wall.h"

Wall :: Wall(int posX) {
	this -> posX = posX; 
	wallTexture.loadFromFile("res/images/wall.png");
	setRandomYPosition();  
	wallSprite = new sf :: Sprite(wallTexture);
	show();
}

void Wall :: setRandomYPosition() {
	this -> posY = (rand() % (Init :: height - wallTexture.getSize().y)) + 1; 
}

void Wall :: move() {
	posX -= dx + (Init :: level - 1) * 2;
	if (-1 * wallTexture.getSize().x <= posX) {
		posX = Init :: width;
		setRandomYPosition();
	}
	show();
}

void Wall :: show() {
	wallSprite -> setPosition(posX, posY);
}

void Wall :: resetWall(int positionX) {
	posX = positionX;
	setRandomYPosition();
	show();
}

Wall :: ~Wall() {
	delete wallSprite;
}
