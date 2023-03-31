#include <raylib.h>
#include <iostream>
#include <string>
#include "coreMechanics.h"
#include <chrono>

using std::chrono::seconds;

struct UPGRADES {
	Texture2D upgradeImage;
	int upgradeCost;
};

// Close game 
void closeGame(bool* exitPtr, Vector2 mousePoint, Rectangle exitButtonHitbox, int screenState)
{
	switch (screenState)
	{
	
	case 1:
	{
		if (WindowShouldClose())
		{
			*exitPtr = true;
		}
		else if (CheckCollisionPointRec(mousePoint, exitButtonHitbox))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				*exitPtr = true;
			}
		}
	}break;

	case 2:
	{
		if (WindowShouldClose())
		{
			*exitPtr = true;
		}
	}break;

	}
}

void changeScreens(Vector2 mousePoint, Rectangle startButtonHitbox, int* menuState)
{
	if (CheckCollisionPointRec(mousePoint, startButtonHitbox))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			*menuState = 2;
		}
	}
}

void showMoneyIncreaser(Vector2 mousePoint, Rectangle flowerHitbox, int moneyIncreaser)
{
	auto countdown = std::chrono::seconds(60);

	if (CheckCollisionPointRec(mousePoint, flowerHitbox))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			DrawText(TextFormat("+%i", moneyIncreaser), mousePoint.x, mousePoint.y, 40, BLACK);
		}
	}
}

// Draw menu textures
void drawMenu(Texture2D title,Texture2D startButton, Texture2D exitButton, int width, int height)
{
	DrawTextureEx(title, Vector2{ float(width) / 2 - float(title.width) / 2, 150 - float(title.height) / 2 }, 0, 1, RAYWHITE);
	DrawTextureEx(startButton, Vector2{ float(width) / 2 - float(startButton.width) / 2, 500 - float(startButton.height) / 2 }, 0, 1, RAYWHITE);
	DrawTextureEx(exitButton, Vector2{ float(width) / 2 - float(exitButton.width) / 2, 700 - float(exitButton.height) / 2 }, 0, 1, RAYWHITE);
}

// Draw game textures
void drawMainGame(Texture2D flower, int width, int height, int wallet, Vector2 mousePoint, Rectangle flowerHitbox)
{
	if (CheckCollisionPointRec(mousePoint, flowerHitbox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		DrawTextureEx(flower, Vector2{ (float(width) / 2 - float(flower.width) / 2) + 10, float(height) / 2 - 300 }, 0, 0.95, RAYWHITE);
	}
	else
	{
		DrawTextureEx(flower, Vector2{ float(width) / 2 - float(flower.width) / 2, float(height) / 2 - 300 }, 0, 1, RAYWHITE);
	}
	DrawText(TextFormat("%i", wallet), 50, 50, 30, BLACK);
}