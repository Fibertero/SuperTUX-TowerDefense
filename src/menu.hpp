#ifndef MENU_H
#define MENU_H
#include"raylib.h"
#include<vector>
#include<string>
#include"statements.hpp"
#include"options.hpp"

const int OPTION_X_POSITION_MENU = 330;
const int OPTION_Y_POSITION_MENU = 370;
const int OPTION_Y_DISTANCE_MENU = 30;
const int OPTION_FONT_SIZE_MENU = 20;
const Color OPTION_SELECTED_COLOR_MENU = DARKBLUE;
const Color OPTION_NON_SELECTED_COLOR_MENU = BLACK;

enum MenuOption {
    StartGame,
    LoadGame,
    Option,
    Exit
};

class Menu{
    public:
        int cursorPosition;
        std::vector<std::string> options;

    public:
        Menu();
        void Update(GameState& state);
        void Draw();
        MenuOption GetSelectedOption();
};

void StartGameF();
void LoadGameF();
void OptionsGameF();
void ExitGameF();

#endif