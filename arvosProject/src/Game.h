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
    Model skyModel;
    Texture2D earthMap;
    Texture2D skyTexture;

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