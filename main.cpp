#include<iostream>
//Including libs
#include"raylib.h"

//Including another game files
#include"src/fonts.hpp"
#include"src/menu.hpp"
#include"src/player.hpp"
#include"src/sounds.hpp"
#include"src/tower.hpp"
#include"src/textures.hpp"

int main()
{

    Image windowIcon;
    GameState gameState;
    std::vector<Enemy> enemies;
    playerData playerData;
    GlobalMessage globalMessage;
    float GlobalVolume;

    InitWindow(800, 600, "Tower Defense");

    //Configuring the window icon
    windowIcon = LoadImage("../icons/icon.png");
    ImageFormat(&windowIcon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(windowIcon);

    //Removing exit key
    SetExitKey(KEY_NULL);    

    //Configuring GameState
    gameState = MENU;

    //Configuring enemies
    enemies = InitEnemies();
    enemies.push_back((Enemy){(Vector2){0,0}, 0.1, 50, true});
    enemies.push_back((Enemy){(Vector2){180, 100}, 0.1, 50, true});

    //Configuring the player data
    playerData = {1000};

    ///Configuring the game screens
    auto optionsMenu = OptionsMenu();
    auto menu = Menu();
    auto mapSelect = MapSelect();
    
    //Configuring the globall messages
    globalMessage = {""};

    //Setting the audio
    Audio::Init();
    GlobalVolume = 0.5;
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
                    mapSelect.Update(gameState);
                    break;
                case INGAME:
                    DrawTexture(gameMaps[mapSelect.GetMapChoosed()].texture, 0, 0, WHITE);
                    for(int i = 0; i<enemies.size(); ++i){
                        enemies[i].Update(enemies, gameMaps[mapSelect.GetMapChoosed()+1]);
                        enemies[i].Draw();
                    }
                    break;
            }
            
            if(optionsMenu.globalBooleans["DrawFPS"])DrawFPS(10,10);
            if(globalMessage.text!="") globalMessage.DrawMessage();
        EndDrawing();
    }
    Audio::ShutDown();
    Textures::ShutDown();
    Fonts::ShutDown();
    mapSelect.UnloadMaps();
    UnloadImage(windowIcon); //organizar esse unload
    CloseWindow();
}