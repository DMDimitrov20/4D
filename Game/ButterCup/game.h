#pragma once
#include <raylib.h>

// Initialize a structure for the game storage
struct STORAGE {
	double cElementCount;
	double hElementCount;
};

// Initialize structure for upgrades
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

// Initialize structure for flowers
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

// Initialize structure for flowers in the garden
struct GARDEN_FLOWER {
	float xCor;
	float yCor;
	Texture2D flowerImage;
};


void startGame();