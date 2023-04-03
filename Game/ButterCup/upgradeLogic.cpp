#include <raylib.h>
#include <vector>
#include "game.h"
#include "upgradeLogic.h"

// System for buying upgrades
void upgradeBuySystem(STORAGE* storagePtr, UPGRADE* upgradeArrPtr, double* defaultMoneyIncreaser, Vector2 mousePoint)
{
	for (int i = 0; i < 3; i++)
	{
		// Check if upgrade is available
		if (storagePtr->cElementCount >= upgradeArrPtr[i].cElementCost && storagePtr->hElementCount >= upgradeArrPtr[i].hElementCost)
		{
			upgradeArrPtr[i].affordable = true;
		}
		else
		{
			upgradeArrPtr[i].affordable = false;
		}

		// Buy upgrade
		if (upgradeArrPtr[i].affordable)
		{
			if (CheckCollisionPointRec(mousePoint, upgradeArrPtr[i].hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				upgradeArrPtr[i].upgradeCount++;
				storagePtr->cElementCount -= upgradeArrPtr[i].cElementCost;
				storagePtr->hElementCount -= upgradeArrPtr[i].hElementCost;
				*defaultMoneyIncreaser += upgradeArrPtr[i].moneyIncreaser;
				upgradeArrPtr[i].cElementCost *= 2;
				upgradeArrPtr[i].hElementCost *= 2;
			}
		}
	}
}

void flowerBuySystem(double* wallet, FLOWER* flowerArrPtr, double* oxygenInsreaser, Vector2 mousePoint, std::vector<GARDEN_FLOWER>* gardenFlowers)
{
	for (int i = 0; i < 3; i++)
	{
		// Check if upgrade is available
		if (*wallet >= flowerArrPtr[i].price)
		{
			flowerArrPtr[i].affordable = true;
		}
		else
		{
			flowerArrPtr[i].affordable = false;
		}

		// Buy upgrade
		if (flowerArrPtr[i].affordable)
		{
			if (CheckCollisionPointRec(mousePoint, flowerArrPtr[i].hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				flowerArrPtr[i].flowerCount++;
				*wallet -= flowerArrPtr[i].price;
				*oxygenInsreaser += flowerArrPtr[i].oxygenIncreaser;
				flowerArrPtr[i].price *= 2;

				GARDEN_FLOWER flower;
				flower.xCor = GetRandomValue(230, 400);
				flower.yCor = GetRandomValue(450, 600);
				flower.flowerImage = flowerArrPtr[i].image;

				gardenFlowers->push_back(flower);

			}
		}
	}
}