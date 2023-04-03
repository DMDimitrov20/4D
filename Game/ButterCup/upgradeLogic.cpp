#include <raylib.h>
#include <vector>
#include <cmath>
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

// System for buying flowers
void flowerBuySystem(double* wallet, FLOWER* flowerArrPtr, double* elementsIncreaserPtr, double* oxygenIncreaserPtr,  Vector2 mousePoint, std::vector<GARDEN_FLOWER>* gardenFlowers)
{
	for (int i = 0; i < 3; i++)
	{
		// Check if flower is available
		if (*wallet >= flowerArrPtr[i].price)
		{
			flowerArrPtr[i].affordable = true;
		}
		else
		{
			flowerArrPtr[i].affordable = false;
		}

		// Buy flower
		if (flowerArrPtr[i].affordable)
		{
			if (CheckCollisionPointRec(mousePoint, flowerArrPtr[i].hitbox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				flowerArrPtr[i].flowerCount++;
				*wallet -= flowerArrPtr[i].price;
				*oxygenIncreaserPtr += flowerArrPtr[i].elementIncreaser;
				*elementsIncreaserPtr = round(*elementsIncreaserPtr * flowerArrPtr[i].elementIncreaser);
				flowerArrPtr[i].price *= 2;

				GARDEN_FLOWER flower;
				flower.xCor = GetRandomValue(230, 400);
				flower.yCor = GetRandomValue(550, 700);
				flower.flowerImage = flowerArrPtr[i].image;

				gardenFlowers->push_back(flower);

			}
		}
	}
}