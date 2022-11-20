#include "Plane.h"

Plane::Plane()
{
	planePos = { 0.0f, 82.0f, 0.0f };
}

void Plane::start()
{
	planeModel = LoadModel("../assets/3dObjects/plane.obj");
	planeTexture = LoadTexture("../assets/images/planeTexture.png");
	SetMaterialTexture(&planeModel.materials[0], MATERIAL_MAP_DIFFUSE, planeTexture);
}

void Plane::update(float elapsedTime)
{
	// plane movement update
	move(elapsedTime);
	turn(elapsedTime);

	DrawModel(planeModel, planePos, 1.0f, WHITE);
}

void Plane::move(float elapsedTime) // handling the movement/rotation
{	
	// calculating the direction
	direction = { 0, 0, 0 };
	direction.x = sin(DEG2RAD * rotation.z) * cos(DEG2RAD * -rotation.x);
	direction.z = cos(DEG2RAD * rotation.z) * cos(DEG2RAD * -rotation.x);

	// locking the movement forward
	planePos.x += direction.x * planeSpeed;
	planePos.z += direction.z * planeSpeed;

	// change direction/rotation
	if (IsKeyDown('A'))
		rotation.z += 1;
	if (IsKeyDown('D'))
		rotation.z -= 1;
	if (IsKeyDown('E') && planeSpeed <= 2.0f)
	{
		planeSpeed += 0.05f;
		rotationSpeed += 0.2;
	}
	else if (IsKeyDown('Q') && planeSpeed > 0.6f)
	{
		planeSpeed -= 0.025f;
		rotationSpeed -= 0.2;
	}
	else if (planeSpeed < 0.6f)
	{
		planeSpeed = 0.4;
	}

	// going up and down
	if (IsKeyDown('W') && planePos.y <= 150.0f)
	{
		planePos.y += 0.5f;
		if (rotation.y > -25)
			rotation.y -= rotationSpeed;
		else rotation.y -= 0.001;
	}
	else if (IsKeyDown('S') && planePos.y >= 60.0f)
	{
		planePos.y -= 0.5f;
		if (rotation.y < 25)
			rotation.y += rotationSpeed;
		else rotation.y += 0.001;
	}
	else
	{
		if (rotation.y < 0)
			rotation.y += 0.5;
		else if (rotation.y > 0)
			rotation.y -= 0.5;
	}

	// handling yaw rotation
	if (IsKeyDown('D'))
	{
		if (rotation.x < 35) 
			rotation.x += rotationSpeed;
		else rotation.x += 0.001;
	}
	else if (IsKeyDown('A')) 
	{
		if (rotation.x > -35) 
			rotation.x -= rotationSpeed;
		else  rotation.x -= 0.001;
	}
	else
	{
		if (rotation.x < 0 )
			rotation.x += 0.5;
		else if (rotation.x > 0 )
			rotation.x -= 0.5;
	}
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