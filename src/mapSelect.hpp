#include "raylib.h"
#include<string>
#include<vector>

struct Map{
    std::string name;
    int id;
    std::string pathToFile;
    Texture2D image;
};

extern std::vector<Map> gameMaps;

class MapSelect
{
    public:
        // Número total de mapas disponíveis
        static const int NUM_MAPS = 4;
        
        // Tamanho dos botões de seleção de mapas
        static const int BUTTON_WIDTH = 200;
        static const int BUTTON_HEIGHT = 50;

        MapSelect();

        void Draw();

        void Update();
    private:
        Rectangle mapButtons[NUM_MAPS];
        int currentMapIndex;
};