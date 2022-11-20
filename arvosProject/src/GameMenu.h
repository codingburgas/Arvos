#pragma once
#include <iostream>
#include "raylib.h"

class GameMenu
{
    // variables init
private:
    Vector2 windowSize = { 1600, 900 };
    Vector2 mousePos;
    bool menuShouldClose = false;
    bool menuNext = false;
    bool infoMenu = false;

    // resources
    Texture2D background;
    Image logo;
    Rectangle playButton = { 300.0f, 80.0f, 650.0f, 255.0f };
    Rectangle infoButton = { 1425.0f, 44.0f, 62.0f, 62.0f };
    Rectangle exitButton = { 300.0f, 80.0f, 650.0f, 405.0f };


    // constructor and deconstructor
public:
    ~GameMenu();


    // functions
public:
    void start();
    void update();
};