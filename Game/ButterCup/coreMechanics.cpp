#include <raylib.h>
#include "coreMechanics.h"


// Close game 
void closeGame(bool* exitPtr, Vector2 mousePoint, Rectangle exitButtonHitbox)
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

// Draw menu textures
void drawMenu(Texture2D title,Texture2D startButton, Texture2D exitButton, int width, int height)
{
	DrawTextureEx(title, Vector2{ float(width) / 2 - float(title.width) / 2, 150 - float(title.height) / 2 }, 0, 1, RAYWHITE);
	DrawTextureEx(startButton, Vector2{ float(width) / 2 - float(startButton.width) / 2, 500 - float(startButton.height) / 2 }, 0, 1, RAYWHITE);
	DrawTextureEx(exitButton, Vector2{ float(width) / 2 - float(exitButton.width) / 2, 700 - float(exitButton.height) / 2 }, 0, 1, RAYWHITE);
}

// Draw game textures
void drawMainGame(Texture2D flower)
{
	DrawTextureEx(flower, Vector2{ 100,100 }, 0, 1, RAYWHITE);
}