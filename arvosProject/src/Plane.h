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
    Vector3 direction = {0, 0, 0};
    Vector3 rotation = { 0, 0, 0 };
    float planeSpeed = 0.02f;
    float rotationSpeed = 1.1f;
    float backRotationSpeed = 0.6f;
    float turningSpeed = 1.3f;

    // resources
    Model planeModel;
    Texture2D planeTexture;

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