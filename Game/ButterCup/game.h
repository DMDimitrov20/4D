#pragma once
#include <raylib.h>

struct STORAGE {
	double cElementCount;
	double hElementCount;
};

struct UPGRADE {
	Texture2D image;
	const char* name;
	double cElementCost;
	double hElementCost;
	bool affordable;
	Rectangle hitbox;
	int upgradeCount = 0;
	double moneyIncreaser;
};

struct FLOWER
{
	Texture2D image;
	const char* name;
	double price;
	bool affordable;
	Rectangle hitbox;
	int flowerCount = 0;
	double oxygenIncreaser;
};


void startGame();