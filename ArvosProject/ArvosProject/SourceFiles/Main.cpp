#include "raylib.h"

int main()
{
	InitWindow(1000, 800, "Arvos");
	SetTargetFPS(60);

	// camera setup :D
	Camera3D camera = { 0 };
	camera.position = { 100.0f, 100.0f, 100.0f };
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up =  {0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	SetCameraMode(camera, CAMERA_FREE);

	// planet setup :DD
	Vector3 planetPos = { 0, 0, 0 };
	Model planet = LoadModelFromMesh(GenMeshSphere(100, 100, 100));
	Texture2D planetText = LoadTexture("Assets/planet.png");
	planet.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = planetText;

	while (!WindowShouldClose())
	{
		UpdateCamera(&camera);
		BeginDrawing();
		ClearBackground(WHITE);
		BeginMode3D(camera);


		DrawModel(planet, planetPos, 1.0f, WHITE);
		

		EndMode3D();
		EndDrawing();
	}

	CloseWindow();

	// unload textures
	UnloadTexture(planetText);
}