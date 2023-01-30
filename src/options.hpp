#ifndef _OPTIONS_H
#define _OPTIONS_H
#include"raylib.h"
#include<vector>
#include<string>
#include"statements.hpp"
#include<unordered_map>

inline const int OPTION_Y_POSITION_OPTIONS = 200;
inline const int OPTION_X_POSITION_OPTIONS = 150;
inline const int DISTANCE_OPTION_PREVIEW = 80; /*The distance of the option preview. Per example, the distance of "Volume" from the current volume value*/
inline const int OPTION_Y_DISTANCE_OPTIONS = 50;
inline const int OPTION_FONT_SIZE_OPTIONS = 20;
inline const Color OPTION_SELECTED_COLOR_OPTIONS = WHITE;
inline const Color OPTION_NON_SELECTED_COLOR_OPTIONS = GRAY;
inline const int TITLE_X_POSITION_OPTIONS = 100;
inline const int TITLE_Y_POSITION_OPTIONS = 100;
inline const int TITLE_FONT_SIZE_OPTIONS = 40;
inline const Color TITLE_COLOR_OPTIONS = LIGHTGRAY;

enum Options{
    VOLUME,
    DRAWFPS,
    FULLSCREEN
};


class OptionsMenu{
    public:
        int cursorPosition;
        std::vector<std::string> options;
        // Option parameters
        std::unordered_map<std::string, bool> globalBooleans;

    public:
        OptionsMenu();
        void Update(float& volume, GameState& gameState);
        void Draw(float& volume, Font textFont);
        Options GetSelectedOption();
};

#endif