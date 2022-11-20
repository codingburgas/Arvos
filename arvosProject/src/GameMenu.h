#pragma once
#include <iostream>
#include "raylib.h"

class GameMenu
{
    // variables init
private:
    Vector2 windowSize = { 1600, 900 };
    Vector2 menuButtonSize = { 320.0f, 110.0f };
    bool menuShouldClose = false;
    bool menuWindowExit = false;

    // resources
    Texture2D background;
    Image logo;
    //Rectangle playButton;
    //Rectangle optionsButton;
    //Rectangle exitButton;


    // constructor and deconstructor
public:
    GameMenu();
    ~GameMenu();


    // functions
public:
    void start();
    void update();
};