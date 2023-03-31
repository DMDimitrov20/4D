#pragma once
#include <raylib.h>

void closeGame(bool *exitPtr, Vector2 mousePoint, Rectangle exitButtonHitbox, int screenState );

void changeScreens(Vector2 mousePoint, Rectangle startButtonHitbox, int* menuState);

void drawMenu(Texture2D title, Texture2D startButton, Texture2D exitButton, int width, int height);

void drawMainGame(Texture2D flower, int width, int height, int wallet, Vector2 mousePoint, Rectangle flowerHitbox);

void showMoneyIncreaser(Vector2 mousePoint, Rectangle flowerHitbox, int moneyIncreaser);