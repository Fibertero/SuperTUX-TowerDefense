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
        if(FileExists(gameMaps[i].pathToFile.c_str())) DrawTexture(gameMaps[i].image, mapButtons[i].x, mapButtons[i].y, WHITE);
        else{ DrawRectangleRec(mapButtons[i], (currentMapIndex==i) ? GREEN : GRAY); } 
        //Draws the current selected map
        DrawText(("Mapa %i", gameMaps[i].name.c_str()), mapButtons[i].x + mapButtons[i].width / 2 - MeasureText("Mapa 1", 30) / 2, mapButtons[i].y + mapButtons[i].height / 2 - 15, 30, YELLOW);
    }
    DrawText(("Mapa selecionado: %i", gameMaps[currentMapIndex].name.c_str()), mapButtons[0].x, mapButtons[0].y-50, 30, WHITE);
}

void MapSelect::Update()
{
    if (IsKeyPressed(KEY_RIGHT))
    {
        // Change to the next map
        currentMapIndex = (currentMapIndex + 1) % NUM_MAPS;
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        // Change to the previous map
        currentMapIndex = (currentMapIndex + NUM_MAPS - 1) % NUM_MAPS;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
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
        newMap.pathToFile = ("../res/maps/map" + std::to_string(i+1) + ".png");
        //Checking if the image exists, setting as preview and resizing it
        if(FileExists(newMap.pathToFile.c_str())){
            auto image = LoadImage(newMap.pathToFile.c_str());
            ImageResize(&image, BUTTON_WIDTH, BUTTON_HEIGHT);
            newMap.image = LoadTextureFromImage(image);
        }
        gameMaps.push_back(newMap);
    }
    // Create the selection map buttons
    for (int i = 0; i < NUM_MAPS; i++)
    {
        // Define the buttons position
        mapButtons[i] = { 
            static_cast<float>((GetScreenWidth() - BUTTON_WIDTH) / 2), // Centraliza horizontalmente
            static_cast<float>((GetScreenHeight() / NUM_MAPS) * i + (GetScreenHeight() / NUM_MAPS - BUTTON_HEIGHT) / 2), // Espaça verticalmente
            BUTTON_WIDTH, 
            BUTTON_HEIGHT 
            };
    }
}