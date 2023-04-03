#pragma once
#include <raylib.h>
#include "game.h"

void closeGame(bool *exitPtr, Vector2 mousePoint, Rectangle exitButtonHitbox, int screenState );

void changeScreens(Vector2 mousePoint, Rectangle startButtonHitbox, int* menuState);

void drawMenu(Texture2D title, Texture2D startButton, Texture2D exitButton, int width, int height);

void drawMainGame(Texture2D money, Texture2D cElementIcon, Texture2D hElementIcon, Texture2D background, Texture2D flower, Texture2D garden, int width, int height, STORAGE storage, Vector2 mousePoint, Rectangle flowerHitbox, int wallet, std::vector<GARDEN_FLOWER> gardenFlowers, double oxygenLevel);

void showMoneyIncreaser(Vector2 mousePoint, Rectangle flowerHitbox, int moneyIncreaser);

void drawUpgradeMenu(Texture2D cElementIcon, Texture2D hElementIcon, UPGRADE upgradeArr[3], Texture2D upgradeFrame, int width, int height, Vector2 mousePoint);

void drawFlowerMenu(Texture2D moneyIcon, FLOWER flowerArr[3], Texture2D upgradeFrame, int width, int height, Vector2 mousePoint);
