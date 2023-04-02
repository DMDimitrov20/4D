#include <raylib.h>
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