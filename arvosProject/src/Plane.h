#pragma once
#include <iostream>
#define RAYMATH_IMPLEMENTATION
#include "raylib.h"
#include "raymath.h"
#include <cmath>
#define _USE_MATH_DEFINES

class Plane
{
    // variables init
private:
    Vector3 planePos;
    float planeSpeed = 12.0f;
    float roll = 0.0f;
    float rotationSpeed = 1.1f;
    float backRotationSpeed = 0.6f;
    float yaw = 0.0f;
    float facingAngle = -90.0f; 
    float turningSpeed = 1.3f;
    float pitch = 0.0f;
    // resources
    Model planeModel;

    // constructor and deconstructor
public:
    Plane();
    ~Plane();


    // functions
public:
    void update(float elapsedTime);
    void start();
    void move(float elapsedTime);
    void turn(float elapsedTime);
    Vector3 getPlanePos();
};