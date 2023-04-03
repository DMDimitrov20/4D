#include <raylib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
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
			DrawText(TextFormat("+%i", moneyIncreaser), mousePoint.x, mousePoint.y, 40, BLACK);
		}
	}
}

// Draw menu textures
void drawMenu(Texture2D title,Texture2D startButton, Texture2D exitButton, int width, int height)
{
	DrawTextureEx(title, Vector2{ float(width) / 2 - float(float(title.width / 2) * 1.5), 145 - float(title.height) / 2 }, 0, 1.5, RAYWHITE);
	DrawTextureEx(startButton, Vector2{ float(width) / 2 - float(startButton.width) / 2, 500 - float(startButton.height) / 2 }, 0, 1, RAYWHITE);
	DrawTextureEx(exitButton, Vector2{ float(width) / 2 - float(exitButton.width) / 2, 700 - float(exitButton.height) / 2 }, 0, 1, RAYWHITE);
}

// Draw game textures
void drawMainGame(Texture2D money, Texture2D cElementIcon, Texture2D hElementIcon, Texture2D background, Texture2D flower, Texture2D garden, int width, int height, STORAGE storage, Vector2 mousePoint, Rectangle flowerHitbox, int wallet, std::vector<GARDEN_FLOWER> gardenFlowers, double oxygenLevel)
{
	DrawTextureEx(background, Vector2{ 0, 0 }, 0, 0.75, RAYWHITE);

	DrawTextureEx(garden, Vector2{ 0, 300 }, 0, 1.25, RAYWHITE);

	DrawText(TextFormat("Oxygen Level %i%%", int(round(oxygenLevel))), 114, 365, 50, BLACK);

	unsigned int vecSize = gardenFlowers.size();

	for (unsigned int i = 0; i < vecSize; i++)
	{
		DrawTextureEx(gardenFlowers[i].flowerImage, { gardenFlowers[i].xCor - gardenFlowers[i].flowerImage.width / 2 + 80, gardenFlowers[i].yCor - gardenFlowers[i].flowerImage.height / 2 + 50 }, 0, 0.4, RAYWHITE);
	}

	if (CheckCollisionPointRec(mousePoint, flowerHitbox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		DrawTextureEx(flower, Vector2{ (float(width) / 2 - float((flower.width / 2) * 1.20)) + 10, float(height) / 2 - 400 }, 0, 1.20, RAYWHITE);
	}
	else
	{
		DrawTextureEx(flower, Vector2{ float(width) / 2 - float((flower.width) / 2 * 1.35), float(height) / 2 - 400 }, 0, 1.35, RAYWHITE);
	}

	DrawTextureEx(cElementIcon, { 46, 54 }, 0, 0.10, RAYWHITE);
	DrawTextureEx(hElementIcon, { 46, 94 }, 0, 0.10, RAYWHITE);
	DrawTextureEx(money, { 44, 134 }, 0, 0.12, RAYWHITE);


	DrawText(TextFormat("%i", int(storage.cElementCount)), 80, 55, 30, BLACK);
	DrawText(TextFormat("%i", int(storage.hElementCount)), 80, 95, 30, BLACK);
	DrawText(TextFormat("%i", wallet), 80, 135, 30, BLACK);
}

// Draw upgrade menu
void drawUpgradeMenu(Texture2D cElementIcon, Texture2D hElementIcon, UPGRADE upgradeArr[3], Texture2D upgradeFrame, int width, int height, Vector2 mousePoint)
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

		DrawTextureEx(cElementIcon, { float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200 }, 0, 0.10, color);
		DrawTextureEx(hElementIcon, { float(width / 2 - upgradeFrame.width / 2) + 913,  float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200 }, 0, 0.10, color);

		DrawText(upgradeArr[i].name, float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 160, 30, color);
		DrawText(TextFormat("%i", int(upgradeArr[i].cElementCost)), float(width / 2 - upgradeFrame.width / 2) + 857, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		DrawText(TextFormat("%i", int(upgradeArr[i].hElementCost)), float(width / 2 - upgradeFrame.width / 2) + 945, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		DrawText(TextFormat("x%i", upgradeArr[i].upgradeCount), float(width / 2 - upgradeFrame.width / 2) + 1046, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		
		positionIncreasement += 120; // Increase position before drawing the next upgrade
	}
}


// Draw flower store
void drawFlowerMenu(Texture2D moneyIcon, FLOWER flowerArr[3], Texture2D upgradeFrame, int width, int height, Vector2 mousePoint)
{
	float initialPosition = -150;
	float positionIncreasement = 0;

	for (int i = 0; i < 3; i++)
	{
		auto color = flowerArr[i].affordable ? RAYWHITE : GRAY; // Check if the flower is affordable and change the color 

		DrawTextureEx(upgradeFrame, { float(width / 2 - upgradeFrame.width / 2) + 700, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement }, 0, 0.8, color);

		if (CheckCollisionPointRec(mousePoint, flowerArr[i].hitbox) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawTextureEx(flowerArr[i].image, { float(width / 2 - upgradeFrame.width / 2) + 710, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 143 }, 0, 0.35, color);
		}
		else
		{
			DrawTextureEx(flowerArr[i].image, { float(width / 2 - upgradeFrame.width / 2) + 713, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 143 }, 0, 0.35, color);
		}

		DrawTextureEx(moneyIcon, { float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200 }, 0, 0.12, color);

		DrawText(flowerArr[i].name, float(width / 2 - upgradeFrame.width / 2) + 825, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 160, 30, color);
		DrawText(TextFormat("%i", int(flowerArr[i].price)), float(width / 2 - upgradeFrame.width / 2) + 860, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);
		DrawText(TextFormat("x%i", flowerArr[i].flowerCount), float(width / 2 - upgradeFrame.width / 2) + 1046, float(height / 2 - upgradeFrame.height / 2) - initialPosition + positionIncreasement + 200, 30, color);

		positionIncreasement += 120; // Increase position before drawing the next upgrade
	}
}