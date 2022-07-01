// Super compact state handling example made by AgitatedAlice in year 2022
// Public domain because this should be standard knowledge and I really have nothing to profit from here
// No liability for damages or anything etcetera etcetera etcetera
#ifndef STATES_H_INCLUDED
#define STATES_H_INCLUDED

// in case ydk declare global variables as externs in their relevant header file, then define them explicitly with the same data type in the relevant source file, and only in one source file!
extern bool g_quit;
extern bool g_isgamewin;

extern unsigned int g_state;

// unsigned integers and enums go very well together in switch statement evals and even in accessing fixed entries in arrays
enum gstates {
    MENU,
    GAME,
    QUIT
};

void gsMenu();
void gsGame();
void gsQuit();

void gsUpdate();



#endif // STATES_H_INCLUDED
