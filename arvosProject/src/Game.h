#pragma once
#include <iostream>
#include "raylib.h"
#include "GameMenu.h"
#include "Plane.h"

class Game
{
    // variables init
private:
    // classes
    GameMenu menu;
    Plane plane;

    // camera
    Camera3D camera = { 0 };

    // resources
    Model planetMap;
    Texture2D earthMap;

    // constructor and deconstructor
public:
    Game();
    ~Game();


    // functions
public:
    void start();
    void update();
    void loadResources();
};