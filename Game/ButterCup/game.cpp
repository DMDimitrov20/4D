#include <raylib.h>
#include "game.h"
#include "coreMechanics.h"

void startGame()
{
	int width = 1920;
	int height = 1080;
	
	InitWindow(width, height, "ButterCup");

	// Initialize mouse pointer
	Vector2 mousePoint = { 0.0f, 0.0f };

	int menuState = 1;
	int* menuStatePtr = &menuState;

	// Intialize game textures
	Texture2D background = LoadTexture("../resources/BackgroundColour.png");
	Texture2D backgroundFrame = LoadTexture("../resources/BackgroundFrame.png");
	Texture2D title = LoadTexture("../resources/ButtercupText.png");
	Texture2D startButton = LoadTexture("../resources/StartButton.png");
	Texture2D exitButton = LoadTexture("../resources/ExitButton.png");
	Texture2D flower = LoadTexture("../resources/FlowerBody.png");

	// Initialize hitboxes
	Rectangle startButtonHitbox = { float(width) / 2 - float(startButton.width) / 2, 500 - float(startButton.height) / 2, startButton.width, startButton.height };
	Rectangle exitButtonHitbox = { float(width) / 2 - float(exitButton.width) / 2, 700 - float(exitButton.height) / 2, exitButton.width, exitButton.height };
	
	// Initialize variable for closing the game
	bool exitWindow = false;
	bool* exitPtr = &exitWindow;

	while (!exitWindow)
	{
		mousePoint = GetMousePosition();

		closeGame(exitPtr, mousePoint, exitButtonHitbox);

		BeginDrawing();
		ClearBackground(BLACK);

		//Draw game background
		DrawTextureEx(background, Vector2{ 0,0 }, 0, 1, RAYWHITE);
		DrawTextureEx(backgroundFrame, Vector2{ 0,0 }, 0, 1, RAYWHITE);

		changeScreens(mousePoint, startButtonHitbox, menuStatePtr);

		// Change screens
		switch (menuState)
		{

		case 1:
		{
			drawMenu(title, startButton, exitButton, width, height);
		}break;

		case 2:
		{
			drawMainGame(flower);
		}break;

		}

		EndDrawing();
	}
}
