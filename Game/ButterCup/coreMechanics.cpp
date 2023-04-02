#include <raylib.h>
#include <iostream>
#include <string>
#include <string.h>
#include "coreMechanics.h"
#include "game.h"


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

// Change screens on button click
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

// Draw money increase value when the flower is pressed
void showMoneyIncreaser(Vector2 mousePoint, Rectangle flowerHitbox, int moneyIncreaser)
{
	if (CheckCollisionPointRec(mousePoint, flowerHitbox))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			DrawText(TextFormat("+%i", moneyIncreaser), mousePoint.x, mousePoint.y, 40, RAYWHITE);
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
void drawMainGame(Texture2D flower, int width, int height, STORAGE storage, Vector2 mousePoint, Rectangle flowerHitbox, int wallet)
{
	if (CheckCollisionPointRec(mousePoint, flowerHitbox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		DrawTextureEx(flower, Vector2{ (float(width) / 2 - float(flower.width) / 2) + 10, float(height) / 2 - 300 }, 0, 0.95, RAYWHITE);
	}
	else
	{
		DrawTextureEx(flower, Vector2{ float(width) / 2 - float(flower.width) / 2, float(height) / 2 - 300 }, 0, 1, RAYWHITE);
	}
	DrawText(TextFormat("C%i", int(storage.cElementCount)), 50, 40, 30, BLACK);
	DrawText(TextFormat("H%i", int(storage.hElementCount)), 50, 80, 30, BLACK);
	DrawText(TextFormat("$%i", wallet), 50, 120, 30, BLACK);
}

// Draw upgrade menu
void drawUpgradeMenu(UPGRADE upgradeArr[3], Texture2D upgradeFrame, int width, int height, Vector2 mousePoint)
{
	float initialPosition = 300;
	float positionIncreasement = 0;

	for (int i = 0; i < 3; i++)
	{
		auto color = upgradeArr[i].affordable ? RAYWHITE : GRAY; // Check if the upgrade is affordable and change the color 

		DrawTextureEx(upgradeFrame, { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement }, 0, 0.8, color);
		
		if (CheckCollisionPointRec(mousePoint, upgradeArr[i].hitbox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawTextureEx(upgradeArr[i].image, { float(width / 2 - upgradeFrame.width / 2) + 710, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 143 }, 0, 0.40, color);
		}
		else
		{
			DrawTextureEx(upgradeArr[i].image, { float(width / 2 - upgradeFrame.width / 2) + 705, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 143 }, 0, 0.45, color);
		}

		DrawText(upgradeArr[i].name, float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 160, 30, color);
		DrawText(TextFormat("C%i", int(upgradeArr[i].cElementCost)), float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		DrawText(TextFormat("H%i", int(upgradeArr[i].hElementCost)), float(width / 2 - upgradeFrame.width / 2) + 900, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		DrawText(TextFormat("x%i", upgradeArr[i].upgradeCount), float(width / 2 - upgradeFrame.width / 2) + 1046, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		
		positionIncreasement += 120; // Increase position before drawing the next upgrade
	}
}

void drawFlowerMenu(FLOWER flowerArr[3], Texture2D upgradeFrame, int width, int height, Vector2 mousePoint)
{
	float initialPosition = -150;
	float positionIncreasement = 0;

	for (int i = 0; i < 3; i++)
	{
		auto color = flowerArr[i].affordable ? RAYWHITE : GRAY; // Check if the upgrade is affordable and change the color 

		DrawTextureEx(upgradeFrame, { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement }, 0, 0.8, color);

		if (CheckCollisionPointRec(mousePoint, flowerArr[i].hitbox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawTextureEx(flowerArr[i].image, { float(width / 2 - upgradeFrame.width / 2) + 710, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 143 }, 0, 0.35, color);
		}
		else
		{
			DrawTextureEx(flowerArr[i].image, { float(width / 2 - upgradeFrame.width / 2) + 713, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 143 }, 0, 0.35, color);
		}

		DrawText(flowerArr[i].name, float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 160, 30, color);
		DrawText(TextFormat("$%i", int(flowerArr[i].price)), float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		DrawText(TextFormat("x%i", flowerArr[i].flowerCount), float(width / 2 - upgradeFrame.width / 2) + 1046, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);

		positionIncreasement += 120; // Increase position before drawing the next upgrade
	}
}