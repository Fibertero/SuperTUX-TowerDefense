#include"mapSelect.hpp"
#include<iostream>

std::vector<Map> gameMaps;

void MapSelect::Draw()
{
    ClearBackground(RAYWHITE);

    for (int i = 0; i < NUM_MAPS; i++)
    {
        //Draws the maps button
        
        //DrawRectangleRec(mapButtons[i], (currentMapIndex==i) ? GREEN : GRAY);
        if(FileExists(gameMaps[i].pathToImageFile.c_str())) DrawTexture(gameMaps[i].texturePreview, mapButtons[i].x, mapButtons[i].y, WHITE);
        else{ DrawRectangleRec(mapButtons[i], (currentMapIndex==i) ? GREEN : GRAY); } 
        //Draws the current selected map
        DrawText(("Mapa %i", gameMaps[i].name.c_str()), mapButtons[i].x + mapButtons[i].width / 2 - MeasureText("Mapa 1", 30) / 2, mapButtons[i].y + mapButtons[i].height / 2 - 15, 30, YELLOW);
    }
    DrawText(("Mapa selecionado: %i", gameMaps[currentMapIndex].name.c_str()), mapButtons[0].x, mapButtons[0].y-50, 30, WHITE);
}

void MapSelect::Update(GameState& state)
{
    if (IsKeyPressed(KEY_RIGHT))
    {
        // Change to the next map
        currentMapIndex = (currentMapIndex + 1) % NUM_MAPS;
    }
    else if (IsKeyPressed(KEY_LEFT))
    {
        // Change to the previous map
        currentMapIndex = (currentMapIndex + NUM_MAPS - 1) % NUM_MAPS;
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();

        for (int i = 0; i < NUM_MAPS; i++)
        {
            if (CheckCollisionPointRec(mousePos, mapButtons[i]))
            {
                currentMapIndex = i;
                //gameMaps[currentMapIndex].function();
                break;
            }
        }
    }
    else if(IsKeyPressed(KEY_ENTER)){
        mapChoosed = gameMaps[currentMapIndex];
        state = INGAME;
    }
}
MapSelect::MapSelect()
{
    currentMapIndex = 0;

    //Create the game maps
    for (int i = 0; i < NUM_MAPS; i++)
    {
        Map newMap;
        newMap.id = i;
        newMap.name = "Mapa " + std::to_string(i+1);
        newMap.pathToImageFile = ("../res/maps/mapPreview" + std::to_string(i+1) + ".png");
        //newMap.enemyPathImage = LoadTexture(("../res/maps/mapPath" + std::to_string(i+1) + ".png").c_str());
        //Checking if the image exists, setting as preview and resizing it
        if(FileExists(newMap.pathToImageFile.c_str())){
            auto image = LoadImage(newMap.pathToImageFile.c_str());
            auto imagePreview = LoadImage(newMap.pathToImageFile.c_str());
            ImageResize(&imagePreview, BUTTON_WIDTH, BUTTON_HEIGHT);
            ImageResize(&image, GetScreenWidth(), GetScreenHeight());
            newMap.texturePreview = LoadTextureFromImage(imagePreview);
            newMap.texture = LoadTextureFromImage(image);

            newMap.enemyPathImage = image;
            UnloadImage(imagePreview);
        }
        else{
            std::cout << "Unable to get map files" << '\n';
        }
        gameMaps.push_back(newMap);
    }
    // Create the selection map buttons
    for (int i = 0; i < NUM_MAPS; i++)
    {
        // Define the buttons position
        mapButtons[i] = { 
            static_cast<float>((GetScreenWidth() - BUTTON_WIDTH) / 2),
            static_cast<float>((GetScreenHeight() / NUM_MAPS) * i + (GetScreenHeight() / NUM_MAPS - BUTTON_HEIGHT) / 2),
            BUTTON_WIDTH, 
            BUTTON_HEIGHT 
            };
    }
}

int MapSelect::GetMapChoosed(){
    return mapChoosed.id;
}

void MapSelect::UnloadMaps(){
    for(int i = 0; i<gameMaps.size(); i++){
        UnloadTexture(gameMaps[i].texture);
        UnloadTexture(gameMaps[i].texturePreview); 
    }
}