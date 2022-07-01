// Super compact state handling example made by AgitatedAlice in year 2022
// Public domain because this should be standard knowledge and I really have nothing to profit from here
// No liability for damages or anything etcetera etcetera etcetera
#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <raymath.h>

#include "states.h"

int main(void)
{
    const int scrW = 640; const int scrH = 480;

    InitWindow(scrW, scrH, "AA Special Solutions");

    SetTargetFPS(60);

    SetExitKey(KEY_END);

    while(!WindowShouldClose()&&g_quit==false){
        gsUpdate();
    }
    CloseWindow();

    return 0;
}

