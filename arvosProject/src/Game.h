#pragma once
#include <iostream>
#include "raylib.h"
#include "GameMenu.h"

class Game
{
    // variables init
private:
    // classes
    GameMenu menu;

    // camera
    Camera3D camera = { 0 };

    // resources
    Model test;

    // contructor and deconstructor
public:
    Game();
    ~Game();


    // functions
public:
    void start();
    void update();
    void loadResources();
};