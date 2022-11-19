#include "Plane.h"

double toRadian(double degrees)
{
	return (degrees * PI) / 180.0;
}

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
	move(elapsedTime);
	turn(elapsedTime);

	DrawModel(planeModel, planePos, 1.0f, LIGHTGRAY);
}

void Plane::move(float elapsedTime)
{	
	const float facingRadian = toRadian(static_cast<double>(facingAngle) + 180.0f);
	if (facingAngle > 360) facingAngle = 0;

	const float XX = planePos.x + planeSpeed * elapsedTime * cos(facingRadian);
	const float ZZ = planePos.z + planeSpeed * elapsedTime * sin(facingRadian);

	planePos.x = XX;
	planePos.z = ZZ;
}

void Plane::turn(float elapsedTime)
{
	if (IsKeyDown(KEY_A))
	{
		if (roll >= -0.7f)
		{
			roll -= rotationSpeed * elapsedTime;
		}
		else
		{
			roll -= 0.0001f * elapsedTime;
		}
		facingAngle -= turningSpeed;
		yaw += turningSpeed * elapsedTime;
	}
	else if (IsKeyDown(KEY_D))
	{
		if (roll <= 0.7f)
		{
			roll += rotationSpeed * elapsedTime;
		}
		else
		{
			roll += 0.0001f * elapsedTime;
		}
		yaw -= turningSpeed * elapsedTime;
		facingAngle += turningSpeed;
	}
	else
	{
		if (roll <= 0.0f) roll += backRotationSpeed * elapsedTime;
		else if (roll >= 0.0f) roll -= backRotationSpeed * elapsedTime;
	}

	planeModel.transform = MatrixRotateXYZ(Vector3{ pitch , yaw, roll });
}

Vector3 Plane::getPlanePos()
{
	return planePos;
}

Plane::~Plane()
{
	UnloadModel(planeModel);
}