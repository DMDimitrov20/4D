#include <raylib.h>
#include "moneyLogic.h"
#include "game.h"

// Add money on flower click
void earnElements(Vector2 mousePoint, Rectangle flowerHitbox, STORAGE* storagePtr, double elementsInreaser)
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
				storagePtr->cElementCount += elementsInreaser;
			}break;

			case 2:
			{
				storagePtr->hElementCount += elementsInreaser;
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