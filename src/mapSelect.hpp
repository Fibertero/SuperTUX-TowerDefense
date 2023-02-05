#ifndef MAPSELECT_H
#define MAPSELECT_H
#include "raylib.h"
#include<string>
#include<vector>
#include"menu.hpp"

typedef struct{
    std::string name;
    int id;
    std::string pathToImageFile;
    Texture2D texturePreview;
    Texture2D texture;
    Image enemyPathImage;
}Map;

extern std::vector<Map> gameMaps;

class MapSelect
{
    public:
        // Número total de mapas disponíveis
        static inline const int NUM_MAPS = 2;
        
        // Tamanho dos botões de seleção de mapas
        static inline const int BUTTON_WIDTH = 200;
        static inline const int BUTTON_HEIGHT = 50;

        MapSelect();

        void Draw();

        void Update(GameState& state);

        int GetMapChoosed();

        void UnloadMaps();
    private:
        Rectangle mapButtons[NUM_MAPS];
        int currentMapIndex;
        Map mapChoosed;
};

#endif