#include <raylib.h>
#include "game.h"


UPGRADE* initializeUpgrades(Texture2D upgradeFrame, int width, int height)
{
	UPGRADE* upgradeArr = new UPGRADE[3];
	float positionIncreasement = 120;

	upgradeArr[0].name = "Alanine";
	upgradeArr[0].cElementCost = 3;
	upgradeArr[0].hElementCost = 7;
	upgradeArr[0].affordable = false;
	upgradeArr[0].image = LoadTexture("../resources/upgrades/Alanine.png");
	upgradeArr[0].hitbox = { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) - 159, float(upgradeArr[0].image.width) + 154, float(upgradeArr[0].image.height) - 140};
	upgradeArr[0].moneyIncreaser = 1;

	upgradeArr[1].name = "Hydroxyproline";
	upgradeArr[1].cElementCost = 5;
	upgradeArr[1].hElementCost = 9;
	upgradeArr[1].affordable = false;
	upgradeArr[1].image = LoadTexture("../resources/upgrades/Hydroxyproline.png");
	upgradeArr[1].hitbox = { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) - 159 + positionIncreasement, float(upgradeArr[1].image.width) + 154, float(upgradeArr[0].image.height) - 140 };
	upgradeArr[1].moneyIncreaser = 5;

	upgradeArr[2].name = "Gibberellic Acid";
	upgradeArr[2].cElementCost = 19;
	upgradeArr[2].hElementCost = 22;
	upgradeArr[2].affordable = false;
	upgradeArr[2].image = LoadTexture("../resources/upgrades/GibberellicAcid.png");
	upgradeArr[2].hitbox = { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) - 159 + (positionIncreasement) * 2, float(upgradeArr[2].image.width) + 154, float(upgradeArr[0].image.height) - 140 };
	upgradeArr[2].moneyIncreaser = 10;

	return upgradeArr;
}

FLOWER* initializeFlowers(Texture2D upgradeFrame, int width, int height)
{
	FLOWER* flowerArr = new FLOWER[3];
	float positionIncreasement = 120;

	flowerArr[0].name = "Spider Plant";
	flowerArr[0].price = 1000;
	flowerArr[0].affordable = false;
	flowerArr[0].image = LoadTexture("../resources/upgrades/SpiderPlant.png");
	flowerArr[0].hitbox = { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) + 290, float(flowerArr[0].image.width) + 154, float(flowerArr[0].image.height) - 140 };
	flowerArr[0].oxygenIncreaser = 0.1;

	flowerArr[1].name = "Snake Plant";
	flowerArr[1].price = 2500;
	flowerArr[1].affordable = false;
	flowerArr[1].image = LoadTexture("../resources/upgrades/SnakePlant.png");
	flowerArr[1].hitbox = { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) + 290 + positionIncreasement, float(flowerArr[1].image.width) + 154, float(flowerArr[0].image.height) - 140 };
	flowerArr[1].oxygenIncreaser = 0.2;

	flowerArr[2].name = "Gerbera Daisy";
	flowerArr[2].price = 10000;
	flowerArr[2].affordable = false;
	flowerArr[2].image = LoadTexture("../resources/upgrades/GerberaDaisy.png");
	flowerArr[2].hitbox = { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) + 290 + (positionIncreasement) * 2, float(flowerArr[2].image.width) + 154, float(flowerArr[0].image.height) - 140 };
	flowerArr[2].oxygenIncreaser = 0.5;

	return flowerArr;
}