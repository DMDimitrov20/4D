#pragma once
#include <raylib.h>
#include <vector>
#include "game.h"
#include "upgradeLogic.h"

void upgradeBuySystem(STORAGE* storagePtr, UPGRADE* upgradeArrPtr, double* defaultMoneyIncreaser, Vector2 mousePoint);

void flowerBuySystem(double* wallet, FLOWER* flowerArrPtr, double* elementsIncreaserPtr, double* oxygenIncreaserPtr, Vector2 mousePoint, std::vector<GARDEN_FLOWER>* gardenFlowers);