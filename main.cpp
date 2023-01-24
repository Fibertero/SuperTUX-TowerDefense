#include<iostream>
#include"raylib.h"
#include"src/tower.hpp"
#include"src/player.hpp"

int main()
{
    InitWindow(800, 600, "Tower Defense");

    playerData playerData = {1000};

    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLUE);

            DrawFPS(10,10);
        EndDrawing();
    }
}