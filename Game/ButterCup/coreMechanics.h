#pragma once
#include <raylib.h>
#include "game.h"

void closeGame(bool *exitPtr, Vector2 mousePoint, Rectangle exitButtonHitbox, int screenState );

void changeScreens(Vector2 mousePoint, Rectangle startButtonHitbox, int* menuState);

void drawMenu(Texture2D title, Texture2D startButton, Texture2D exitButton, int width, int height);

void drawMainGame(Texture2D flower, int width, int height, STORAGE storage, Vector2 mousePoint, Rectangle flowerHitbox, int wallet);

void showMoneyIncreaser(Vector2 mousePoint, Rectangle flowerHitbox, int moneyIncreaser);

void drawUpgradeMenu(UPGRADE upgradeArr[3], Texture2D upgradeFrame, int width, int height, Vector2 mousePoint);