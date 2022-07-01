// Super compact state handling example made by AgitatedAlice in year 2022
// Public domain because this should be standard knowledge and I really have nothing to profit from here
// No liability for damages or anything etcetera etcetera etcetera

#include <math.h>
#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

#include "states.h"

// in case ydk declare global variables as externs in their relevant header file, then define them explicitly with the same data type in the relevant source file, and only in one source file!
// here they are explicitly defined
bool g_quit = false; bool g_isgamewin = false;
unsigned int g_state = 0;

// get used to switch statements they are super fast, most compilers turn them into simple jumps with addr mapped to the case
void gsUpdate()
{
    switch(g_state){
    case MENU:
        gsMenu(); break;
    case GAME:
        gsGame(); break;
    case QUIT:
        gsQuit(); break;
    }
}

void gsMenu(){
    float sW = (float)GetScreenWidth(); float sH = (float)GetScreenHeight();
    Rectangle GameButton = {(sW/2.0f)-64.0f, sH/4.0f, 128.0f, 64.0f};
    Rectangle QuitButton = {(sW/2.0f)-64.0f, (sH/4.0f)+128.0f, 128.0f, 64.0f};

    BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleLinesEx(GameButton, 4, GREEN); DrawText("GAME", (int)(GameButton.x+(GameButton.width/2.0f)-(float)MeasureText("GAME", 16)/2.0f), (int)(GameButton.y+(GameButton.height/2.0f)-8.0f), 16, LIME);
        DrawRectangleLinesEx(QuitButton, 4, RED); DrawText("QUIT", (int)(QuitButton.x+(QuitButton.width/2.0f)-(float)MeasureText("QUIT", 16)/2.0f), (int)(QuitButton.y+(QuitButton.height/2.0f)-8.0f), 16, RED);
    EndDrawing();

    Vector2 mpos = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointRec(mpos, GameButton)){g_state = GAME;}
        else if(CheckCollisionPointRec(mpos, QuitButton)){g_state = QUIT;}
    }
}



void gsGame(){

    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("GAME IS PLAY!!! ESC FOR MENU!!!", 0, 0, 8, YELLOW);
        if(g_isgamewin){
             DrawRectangleGradientV(GetScreenWidth()/2, GetScreenHeight()/2, 64, 64, LIME, MAGENTA);
             DrawText("GAME IS WIN!!!", GetScreenWidth()/2, GetScreenHeight()/2, 16, ORANGE);
        }
    EndDrawing();

    if(IsKeyPressed(KEY_ESCAPE)){g_state = MENU;}
    else if (IsKeyPressed(KEY_G)){g_isgamewin = true;};
}

void gsQuit(){
    g_quit = true;
}
