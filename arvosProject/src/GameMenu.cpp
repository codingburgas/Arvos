#include "GameMenu.h"

GameMenu::GameMenu()
{
}

void GameMenu::update() 
{
	while (!menuShouldClose)
	{
		if (WindowShouldClose())
		{
			std::exit(0);
		}
		if (IsKeyDown(KEY_LEFT_SHIFT))
		{
			menuShouldClose = true;
		}
		ClearBackground(RAYWHITE);
		BeginDrawing();
		DrawText("Menu: Hello :D", (GetScreenWidth() / 2 - 150), (GetScreenHeight() / 2 - 20), 40, GRAY);
		EndDrawing();
	}
}

GameMenu::~GameMenu()
{

}