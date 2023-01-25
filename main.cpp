#include<iostream>
#include"raylib.h"
#include"src/tower.hpp"
#include"src/player.hpp"
#include"src/menu.hpp"
#include"src/sounds.hpp"
#include"src/textures.hpp"

int main()
{
    InitWindow(800, 600, "Tower Defense");

    //Setting GameState
    GameState gameState = MENU;

    //Setting the player data
    playerData playerData = {1000};

    ///Setting the options menu
    auto optionsMenu = OptionsMenu();

    //Setting the main menu
    auto menu = Menu();

    //Setting the audio
    Audio::Init();
    //Setting the textures
    Textures::Init();

    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_ENTER)) PlaySound(Audio::GetSound("click"));
        BeginDrawing();
            ClearBackground(BLUE);
            switch(gameState){
                case MENU:
                    DrawTexture(Textures::Get("background"), 0, 0, WHITE);
                    menu.Draw();
                    menu.Update(gameState);
                    break;
                case OPTIONS:
                    optionsMenu.Draw();
                    optionsMenu.Update();
                    break;
            }
            
            DrawFPS(10,10);
        EndDrawing();
    }
    Audio::ShutDown();
    Textures::ShutDown();
    CloseWindow();
}