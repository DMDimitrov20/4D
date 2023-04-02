#include <raylib.h>
#include "moneyLogic.h"
#include "game.h"

// Add money on flower click
void earnElements(Vector2 mousePoint, Rectangle flowerHitbox, STORAGE* storagePtr, double moneyInreaser)
{
	if (CheckCollisionPointRec(mousePoint, flowerHitbox))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			int randomElement = GetRandomValue(1, 2);

			switch (randomElement)
			{
			case 1:
			{
				storagePtr->cElementCount += 1;
			}break;

			case 2:
			{
				storagePtr->hElementCount += 1;
			}
			}
		}
	}
}

// Add money as a default increase
void defaultMoneyIncrease(double* walletPtr, double defaultMoneyIncreaser)
{
	int chance = GetRandomValue(1, 20);

	if (chance == 20)
	{
		*walletPtr += defaultMoneyIncreaser;
	}
}