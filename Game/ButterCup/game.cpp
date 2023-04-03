#include <raylib.h>
#include <iostream>
#include <vector>
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

	// Initialize player's wallet
	double wallet = 1000000;
	double* walletPtr = &wallet;

	//Initialize oxygen level
	double oxygenLevel = 0;
	double* oxygenLevelPtr = &oxygenLevel;
	
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
	Texture2D gameBackground = LoadTexture("../resources/GameBackground.png");
	Texture2D title = LoadTexture("../resources/ButtercupText.png");
	Texture2D startButton = LoadTexture("../resources/StartButton.png");
	Texture2D exitButton = LoadTexture("../resources/ExitButton.png");
	Texture2D flower = LoadTexture("../resources/Flower.png");
	Texture2D upgradeFrame = LoadTexture("../resources/upgrades/upgradeTable.png");
	Texture2D flowerFrame = LoadTexture("../resources/upgrades/FlowerTable.png");
	Texture2D garden = LoadTexture("../resources/garden.png");

	// Initialize upgrade array
	UPGRADE* upgradeArr = initializeUpgrades(upgradeFrame, width, height);

	// Initialize flower array
	FLOWER* flowerArr = initializeFlowers(upgradeFrame, width, height);

	// Initialize garden flowers storage
	std::vector<GARDEN_FLOWER> gardenFlowers;
	std::vector<GARDEN_FLOWER>* gardenFlowersPtr = &gardenFlowers;

	// Initialize hitboxes
	Rectangle startButtonHitbox = { float(width) / 2 - float(startButton.width) / 2, 500 - float(startButton.height) / 2, startButton.width, startButton.height };
	Rectangle exitButtonHitbox = { float(width) / 2 - float(exitButton.width) / 2, 700 - float(exitButton.height) / 2, exitButton.width, exitButton.height };
	Rectangle flowerHitbox  = { float(width) / 2 - float(flower.width) / 2, float(height) / 2 - 300, flower.width, flower.height };
	Rectangle rec = { 210, 430, 210, 190 };
	
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

			upgradeBuySystem(storagePtr, upgradeArr, defaultMoneyIncreaserPtr, mousePoint);

			defaultMoneyIncrease(walletPtr, defaultMoneyIncreaser);

			flowerBuySystem(walletPtr, flowerArr, oxygenLevelPtr, mousePoint, gardenFlowersPtr);
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
			drawMainGame(gameBackground, flower, garden, width, height, storage, mousePoint, flowerHitbox, wallet, gardenFlowers);

			showMoneyIncreaser(mousePoint, flowerHitbox, moneyIncreaser);

			drawUpgradeMenu(upgradeArr, upgradeFrame, width, height, mousePoint);

			drawFlowerMenu(flowerArr, flowerFrame, width, height, mousePoint);
		}break;

		}

		EndDrawing();
	}
}
