#include "Game.h"

Game::Game()
{
    menu.start();
    start();
}

void Game::start()
{
    // camera setup
    camera.position = { 0.0f, 100.0f, 0.0f };
    camera.target = { 0.0f, 82.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_FREE);

    update();
}

void Game::loadResources()
{
    planetMap = LoadModel("../assets/3dObjects/earth.obj");
    earthMap = LoadTexture("../assets/images/earthMap.png");
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

        BeginDrawing();
        ClearBackground(Color{ 215, 226, 245, 255 });
        // 3d drawning
        BeginMode3D(camera);

        DrawModel(planetMap, Vector3{ 2.0f, 2.0f, 2.0f }, 100.0f, WHITE);

        // draw and update plane
        plane.update(GetFrameTime());

        // camera update
        camera.target = plane.getPlanePos();
        camera.position = { plane.getPlanePos().x, plane.getPlanePos().y + 28.0f , plane.getPlanePos().z };

        EndMode3D();

        // 2d drawing
        if(menu.displayFps()) DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
}

Game::~Game()
{
    // unloading resources
    UnloadModel(planetMap);
    UnloadTexture(earthMap);
}