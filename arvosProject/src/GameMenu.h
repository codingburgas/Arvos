#pragma once
#include <iostream>
#include "raylib.h"

class GameMenu
{
    // variables init
private:
    bool menuShouldClose = false;
    bool menuWindowExit = false;

    // resources


    // constructor and deconstructor
public:
    GameMenu();
    ~GameMenu();


    // functions
public:
    void update();
};