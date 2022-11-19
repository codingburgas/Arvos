#include "Game.h"

Game::Game()
{
    menu.start();
    start();
}

void Game::start()
{
    // camera setup
    camera.position = { 20.0f, 20.0f, 20.0f };
    camera.target = plane.getPlanePos();
    camera.up = { 0.0f, 10.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_FREE);

    update();
}

void Game::loadResources()
{
    planetMap = LoadModel("../assets/3dObjects/earth.obj");
    Texture2D earthMap = LoadTexture("../assets/images/earthMap.png");
    planetMap.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = earthMap;
}

void Game::update()
{
    loadResources();
    plane.start();
    // main gameloop
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode3D(camera);

        // draw
        DrawModel(planetMap, Vector3{ 2.0f, 2.0f, 2.0f }, 1.0f, BLUE);
        DrawGrid(80, 1.0f);

        // draw and update plane
        plane.update(GetFrameTime());
        camera.position = { plane.getPlanePos().x, plane.getPlanePos().y + 10.0f , plane.getPlanePos().z };
        camera.target = plane.getPlanePos();

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
    UnloadModel(planetMap);
}