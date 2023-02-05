#include<iostream>
//Including libs
#include"raylib.h"

//Including another game files
#include"src/fonts.hpp"
#include"src/menu.hpp"
#include"src/sounds.hpp"
#include"src/textures.hpp"
#include"src/game.hpp"


int main()
{

    Image windowIcon{};
    GameState gameState{};
    std::vector<Enemy> enemies{};
    PlayerData playerData{0};
    GlobalMessage globalMessage{};
    auto game = Game(enemies);
    float GlobalVolume{};

    InitWindow(800, 600, "Tower Defense");

    //Configuring the window icon
    windowIcon = LoadImage("../icons/icon.png");
    ImageFormat(&windowIcon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(windowIcon);

    //Removing exit key
    SetExitKey(KEY_NULL);    

    //Configuring GameState
    gameState = MENU;

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

    //Init the game enemies
    game.Init(6);

    //Configuring castle
    auto castle = Castle(50, 50, (Rectangle){(GetScreenWidth()/2), GetScreenHeight()-Textures::Get("castle").height, Textures::Get("castle").width, Textures::Get("castle").height});


    //Starting the game timer
    StartTimer(game.timer, 0.1f);

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
                    if(TimerDone(game.timer)){ 
                        game.SpawnEnemy();
                        StartTimer(game.timer, 5.0f);
                    }
                    DrawTexture(gameMaps[mapSelect.GetMapChoosed()].texture, 0, 0, WHITE);
                    game.Draw(castle);
                    game.Update(game.enemies, gameMaps[mapSelect.GetMapChoosed()], globalMessage);
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
