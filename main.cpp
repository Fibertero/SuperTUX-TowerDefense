#include<iostream>
#include"raylib.h"
#include"src/tower.hpp"
#include"src/player.hpp"
#include"src/menu.hpp"
#include"src/sounds.hpp"
#include"src/textures.hpp"
#include"src/fonts.hpp"
#include"src/dialogBox.hpp"

int main()
{
    InitWindow(800, 600, "Tower Defense");

    SetExitKey(KEY_NULL);    

    //Setting GameState
    GameState gameState = MENU;

    //Setting the player data
    playerData playerData = {1000};

    ///Setting the options menu
    auto optionsMenu = OptionsMenu();

    //Setting the main menu
    auto menu = Menu();
    
    //Setting the globall messages
    GlobalMessage globalMessage;

    //Setting the audio
    Audio::Init();
    float GlobalVolume = 0.5;
    SetMasterVolume(GlobalVolume);
    //Setting the textures
    Textures::Init();
    //Setting the fonts
    Fonts::Init();

    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_ENTER)) PlaySound(Audio::GetSound("click"));
        BeginDrawing();
            ClearBackground(BLUE);
            switch(gameState){
                case MENU:
                    DrawTexture(Textures::Get("background2"), 0, 0, WHITE);
                    menu.Draw(Fonts::Get("ice1"));
                    menu.Update(gameState);
                    break;
                case OPTIONS:
                    optionsMenu.Draw(GlobalVolume, Fonts::Get("ice1"));
                    optionsMenu.Update(GlobalVolume, gameState);
                    break;
            }
            
            if(optionsMenu.globalBooleans["DrawFPS"])DrawFPS(10,10);
        EndDrawing();
    }
    Audio::ShutDown();
    Textures::ShutDown();
    Fonts::ShutDown();
    CloseWindow();
}