#include <raylib.h>
#include <iostream>
#include "game.h"
#include "coreMechanics.h"
#include "moneyLogic.h"
#include "upgradesInitialization.h"
#include "upgradeLogic.h"

void startGame()
{
	int width = 1920;
	int height = 1080;
	
	InitWindow(width, height, "ButterCup");

	// Initialize chemical elemnts storage
	STORAGE storage;
	STORAGE* storagePtr = &storage;
	storage.cElementCount = 0;
	storage.hElementCount = 0;

	// Initialize g
	double wallet = 0;
	double* walletPtr = &wallet;
	
	// Initialize variable for increasing player's chemicals
	double moneyIncreaser = 1;
	double defaultMoneyIncreaser = 0;
	double* defaultMoneyIncreaserPtr = &defaultMoneyIncreaser;
	
	// Initialize mouse pointer
	Vector2 mousePoint = { 0.0f, 0.0f };

	// Initialize screen variable
	int screenState = 1;
	int* screenStatePtr = &screenState;

	// Intialize game textures
	Texture2D background = LoadTexture("../resources/BackgroundColour.png");
	Texture2D backgroundFrame = LoadTexture("../resources/BackgroundFrame.png");
	Texture2D title = LoadTexture("../resources/ButtercupText.png");
	Texture2D startButton = LoadTexture("../resources/StartButton.png");
	Texture2D exitButton = LoadTexture("../resources/ExitButton.png");
	Texture2D flower = LoadTexture("../resources/Flower.png");
	Texture2D upgradeFrame = LoadTexture("../resources/upgrades/upgradeTable.png");

	// initialize upgrade array
	UPGRADE* upgradeArr = initalizeUpgrades(upgradeFrame, width, height);
	UPGRADE* upgradeArrPtr = upgradeArr;

	// Initialize hitboxes
	Rectangle startButtonHitbox = { float(width) / 2 - float(startButton.width) / 2, 500 - float(startButton.height) / 2, startButton.width, startButton.height };
	Rectangle exitButtonHitbox = { float(width) / 2 - float(exitButton.width) / 2, 700 - float(exitButton.height) / 2, exitButton.width, exitButton.height };
	Rectangle flowerHitbox  = { float(width) / 2 - float(flower.width) / 2, float(height) / 2 - 300, flower.width, flower.height };
	
	// Initialize variable for closing the game
	bool exitWindow = false;
	bool* exitPtr = &exitWindow;

	while (!exitWindow)
	{
		// Get mouse position
		mousePoint = GetMousePosition();

		closeGame(exitPtr, mousePoint, exitButtonHitbox, screenState);
		
		if (screenState == 2)
		{
			earnElements(mousePoint, flowerHitbox, storagePtr, moneyIncreaser);

			upgradeBuySystem(storagePtr, upgradeArrPtr, defaultMoneyIncreaserPtr, mousePoint);

			defaultMoneyIncrease(walletPtr, defaultMoneyIncreaser);
		}

		BeginDrawing();
		ClearBackground(BLACK);

		//Draw game background
		DrawTextureEx(background, Vector2{ 0,0 }, 0, 1, RAYWHITE);
		DrawTextureEx(backgroundFrame, Vector2{ 0,0 }, 0, 1, RAYWHITE);

		changeScreens(mousePoint, startButtonHitbox, screenStatePtr);

		// Change screens
		switch (screenState)
		{

		// Draw menu screen
		case 1:
		{
			drawMenu(title, startButton, exitButton, width, height);
		}break;

		// Draw game screen
		case 2:
		{
			drawMainGame(flower, width, height, storage, mousePoint, flowerHitbox, wallet);

			showMoneyIncreaser(mousePoint, flowerHitbox, moneyIncreaser);

			drawUpgradeMenu(upgradeArr, upgradeFrame, width, height, mousePoint);
		}break;

		}

		EndDrawing();
	}
}
