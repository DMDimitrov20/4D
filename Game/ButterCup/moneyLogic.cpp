#include <raylib.h>
#include "moneyLogic.h"

// Add money on flower click
void addMoney(Vector2 mousePoint, Rectangle flowerHitbox, int* walletPtr, int moneyInreaser)
{
	if (CheckCollisionPointRec(mousePoint, flowerHitbox))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			*walletPtr += moneyInreaser;
		}
	}
}

// Add money as a default increase
void defaultMoneyIncrease(int* walletPtr, int defaultMoneyIncreaser)
{
	int chance = GetRandomValue(1, 15);

	if (chance == 15)
	{
		*walletPtr += defaultMoneyIncreaser;
	}
}