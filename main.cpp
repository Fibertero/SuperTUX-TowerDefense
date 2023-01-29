#include<iostream>
#include"raylib.h"
#include"src/tower.hpp"
#include"src/player.hpp"
#include"src/menu.hpp"
#include"src/sounds.hpp"
#include"src/textures.hpp"
#include"src/fonts.hpp"
#include"src/mapSelect.hpp"

int main()
{
    InitWindow(800, 600, "Tower Defense");

    //Configuring the window icon
    Image icon = LoadImage("../icons/icon.png");
    ImageFormat(&icon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);

    SetWindowIcon(icon);

    //Removing exit key
    SetExitKey(KEY_NULL);    

    //Setting GameState
    GameState gameState = MENU;

    //Setting the player data
    playerData playerData = {1000};

    ///Setting the game screens
    auto optionsMenu = OptionsMenu();
    auto menu = Menu();
    auto mapSelect = MapSelect();
    
    //Setting the globall messages
    GlobalMessage globalMessage = {""};

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
                    menu.Update(gameState, globalMessage);
                    break;
                case OPTIONS:
                    optionsMenu.Draw(GlobalVolume, Fonts::Get("ice1"));
                    optionsMenu.Update(GlobalVolume, gameState);
                    break;
                case MAPSELECT:
                    mapSelect.Draw();
                    mapSelect.Update();
                    break;
            }
            
            if(optionsMenu.globalBooleans["DrawFPS"])DrawFPS(10,10);
            if(globalMessage.text!="") globalMessage.DrawMessage();
        EndDrawing();
    }
    Audio::ShutDown();
    Textures::ShutDown();
    Fonts::ShutDown();
    CloseWindow();
}