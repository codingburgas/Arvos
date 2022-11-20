#include "Plane.h"

Plane::Plane()
{
	planePos = { 0.0f, 15.0f, 0.0f };
}

void Plane::start()
{
	planeModel = LoadModel("../assets/3dObjects/plane.obj");
}

void Plane::update(float elapsedTime)
{
	// plane movement update
	move(elapsedTime);
	turn(elapsedTime);

	DrawModel(planeModel, planePos, 1.0f, LIGHTGRAY);
}

void Plane::move(float elapsedTime) // handling the movement/rotation
{	
	// calculating the direction
	direction = { 0, 0, 0 };
	direction.x = sin(DEG2RAD * rotation.z) * cos(DEG2RAD * -rotation.x);
	direction.z = cos(DEG2RAD * rotation.z) * cos(DEG2RAD * -rotation.x);

	// locking the movement forward
	planePos.x += direction.x * 0.2f;
	planePos.z += direction.z * 0.2f;

	// change direction/rotation
	if (IsKeyDown('A')) rotation.z += 1;
	if (IsKeyDown('D')) rotation.z -= 1;

	if (IsKeyDown('W')) rotation.y += 1;
	if (IsKeyDown('S')) rotation.y -= 1;
}

void Plane::turn(float elapsedTime)
{
	Matrix transform = MatrixIdentity();
	transform = MatrixMultiply(transform, MatrixRotateZ(DEG2RAD * rotation.x));
	transform = MatrixMultiply(transform, MatrixRotateX(DEG2RAD * rotation.y));
	transform = MatrixMultiply(transform, MatrixRotateY(DEG2RAD * rotation.z));
	planeModel.transform = transform;
}

Vector3 Plane::getPlanePos() // returns the plane position vector for outside uses
{
	return planePos;
}

Plane::~Plane()
{
	// unloading recources
	UnloadModel(planeModel);
}