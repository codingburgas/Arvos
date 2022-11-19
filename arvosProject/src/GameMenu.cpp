#include "GameMenu.h"

GameMenu::GameMenu()
{

}

void GameMenu::start()
{
	// window setup
	InitWindow(windowSize.x, windowSize.y, "Arvos");
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
		ClearBackground(WHITE);
		DrawTexture(background, 0, 0, WHITE);


		BeginDrawing();



		EndDrawing();
	}
}

GameMenu::~GameMenu()
{

}