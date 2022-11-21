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
		else if (IsKeyDown(KEY_X) && !menuNext && !infoMenu)
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
				if (showFps)
				{
					background = LoadTexture("../assets/images/infoScreen1.png");
				}
				else
				{
					background = LoadTexture("../assets/images/infoScreen0.png");
				}
			}
			else if (CheckCollisionPointRec(mousePos, exitButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				std::exit(0);
			}
		}
		else if (infoMenu)
		{
			if (CheckCollisionPointRec(mousePos, fpsButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				if (showFps)
				{
					background = LoadTexture("../assets/images/infoScreen0.png");
				}
				else
				{
					background = LoadTexture("../assets/images/infoScreen1.png");
				}
				showFps = !showFps;
			}
			else if (CheckCollisionPointRec(mousePos, backButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				background = LoadTexture("../assets/images/menuScreen.png");
				infoMenu = false;
				menuNext = true;
			}
		}
		BeginDrawing();
		ClearBackground(WHITE);
		DrawTexture(background, 0, 0, WHITE);

		EndDrawing();
	}
}

bool GameMenu::displayFps()
{
	return showFps;
}

GameMenu::~GameMenu()
{
	// unloading resources
	UnloadTexture(background);
}