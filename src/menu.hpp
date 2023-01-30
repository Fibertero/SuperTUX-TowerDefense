#ifndef MENU_H
#define MENU_H
#include"raylib.h"
#include<vector>
#include<string>
#include"options.hpp"
#include"dialogBox.hpp"

inline const int OPTION_X_POSITION_MENU = 330;
inline const int OPTION_Y_POSITION_MENU = 370;
inline const int OPTION_Y_DISTANCE_MENU = 30;
inline const int OPTION_FONT_SIZE_MENU = 20;
inline const Color OPTION_SELECTED_COLOR_MENU = DARKBLUE;
inline const Color OPTION_NON_SELECTED_COLOR_MENU = BLACK;

enum MenuOption {
    STARTGAME,
    OPTION,
    EXIT
};

class Menu{
    public:
        int cursorPosition;
        std::vector<std::string> options;

    public:
        Menu();
        void Update(GameState& state, GlobalMessage& message);
        void Draw(Font textFont);
        MenuOption GetSelectedOption();
};

static void StartGameF();
static void LoadGameF();
static void OptionsGameF();
static void ExitGameF();

#endif