#include "GameMenu.h"

void GameMenu::start()
{
	// window setup
	InitWindow(windowSize.x, windowSize.y, "Arvos");
	logo = LoadImage("../assets/images/logo.png"); 
	SetWindowIcon(logo);
	SetTargetFPS(60);

	background = LoadTexture("../assets/images/mainScreen.png");
	update();
}

void GameMenu::update() 
{
	while (!menuShouldClose)
	{
		if (WindowShouldClose())
		{
			std::exit(0);
		}
		if (IsKeyDown(KEY_X))
		{
			menuShouldClose = true;
		}
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(background, 0, 0, WHITE);

		EndDrawing();
	}
}

GameMenu::~GameMenu()
{
	// unloading resources
	UnloadTexture(background);
}