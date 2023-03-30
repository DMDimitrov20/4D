#pragma once
#include <raylib.h>

void closeGame(bool *exitPtr, Vector2 mousePoint, Rectangle exitButtonHitbox);

void changeScreens(Vector2 mousePoint, Rectangle startButtonHitbox, int* menuState);

void drawMenu(Texture2D title, Texture2D startButton, Texture2D exitButton, int width, int height);

void drawMainGame(Texture2D flower);