#include <raylib.h>
#include "game.h"


UPGRADE* initalizeUpgrades(Texture2D upgradeFrame, int width, int height)
{
	UPGRADE* upgradeArr = new UPGRADE[3];
	float hitboxPosition = 300;
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