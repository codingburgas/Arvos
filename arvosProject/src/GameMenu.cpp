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
		mousePos = GetMousePosition();
		if (WindowShouldClose())
		{
			std::exit(0);
		}
		else if (IsKeyDown(KEY_X) && !menuNext)
		{
			menuNext = true;
			background = LoadTexture("../assets/images/menuScreen.png");
		}
		else if (menuNext)
		{
			if (CheckCollisionPointRec(mousePos, playButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				background = LoadTexture("../assets/images/loadingScreen.png");
				menuShouldClose = true;
			}
			else if (CheckCollisionPointRec(mousePos, infoButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				infoMenu = true;
				menuNext = false;
				background = LoadTexture("../assets/images/menuScreen.png");
			}
			else if (CheckCollisionPointRec(mousePos, exitButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				std::exit(0);
			}
		}
		else if (infoMenu)
		{

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