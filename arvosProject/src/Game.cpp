#include "Game.h"

Game::Game()
{
    // window setup
    InitWindow(1000, 800, "Arvos");
    SetTargetFPS(60);

    menu.update();
    start();
}

void Game::start()
{
    // camera setup
    camera.position = { 20.0f, 20.0f, 20.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 10.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_FREE);

    update();
}

void Game::loadResources()
{
    test = LoadModel("../assets/3dObjects/test.obj");
}

void Game::update()
{
    loadResources();
    // main gameloop
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode3D(camera);

        // draw
        DrawModel(test, Vector3{ 0.0f, 0.0f, 0.0f }, 1.0f, LIME);
        DrawGrid(20, 1.0f);

        EndMode3D();

        // 2d drawing
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
}

Game::~Game()
{
    // unloading resources
    UnloadModel(test);
}