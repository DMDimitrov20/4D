#include <raylib.h>
#include <iostream>
#include "game.h"
#include "coreMechanics.h"
#include "moneyLogic.h"

void startGame()
{
	int width = 1920;
	int height = 1080;
	
	InitWindow(width, height, "ButterCup");

	// initialize game wallet
	int wallet = 0;
	int* walletPtr = &wallet;
	
	// Initialize variable for increasing player's money
	int moneyIncreaser = 1;
	int defaultMoneyIncreaser = 0;
	
	// Initialize mouse pointer
	Vector2 mousePoint = { 0.0f, 0.0f };

	int screenState = 1;
	int* screenStatePtr = &screenState;

	// Intialize game textures
	Texture2D background = LoadTexture("../resources/BackgroundColour.png");
	Texture2D backgroundFrame = LoadTexture("../resources/BackgroundFrame.png");
	Texture2D title = LoadTexture("../resources/ButtercupText.png");
	Texture2D startButton = LoadTexture("../resources/StartButton.png");
	Texture2D exitButton = LoadTexture("../resources/ExitButton.png");
	Texture2D flower = LoadTexture("../resources/Flower.png");

	// Initialize hitboxes
	Rectangle startButtonHitbox = { float(width) / 2 - float(startButton.width) / 2, 500 - float(startButton.height) / 2, startButton.width, startButton.height };
	Rectangle exitButtonHitbox = { float(width) / 2 - float(exitButton.width) / 2, 700 - float(exitButton.height) / 2, exitButton.width, exitButton.height };
	Rectangle flowerHitbox  = { float(width) / 2 - float(flower.width) / 2, float(height) / 2 - 300, flower.width, flower.height };
	
	// Initialize variable for closing the game
	bool exitWindow = false;
	bool* exitPtr = &exitWindow;

	while (!exitWindow)
	{
		mousePoint = GetMousePosition();

		closeGame(exitPtr, mousePoint, exitButtonHitbox, screenState);
		
		if (screenState == 2)
		{
			addMoney(mousePoint, flowerHitbox, walletPtr, moneyIncreaser);

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
			drawMainGame(flower, width, height, wallet, mousePoint, flowerHitbox);

			showMoneyIncreaser(mousePoint, flowerHitbox, moneyIncreaser);
		}break;

		}

		EndDrawing();
	}
}
