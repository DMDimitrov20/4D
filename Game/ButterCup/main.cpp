#include <raylib.h>

int main()
{
	InitWindow(1280, 720, "title");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();
}