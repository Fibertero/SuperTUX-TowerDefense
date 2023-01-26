#include"fonts.hpp"

std::vector<std::string> fontsPath = {"../res/fonts/ice1.otf", "../res/fonts/frosty.ttf"};
std::unordered_map<std::string, Font> fonts;

void Fonts::Load(std::string name, std::string path){
    Font font = LoadFont(path.c_str());
    fonts[name] = font;
}

void Fonts::Init(){
    for(auto font : fontsPath){
        Load(GetFileNameWithoutExt(font.c_str()), font);
    }
}
Font& Fonts::Get(std::string name) {
    return fonts[name];
}

void Fonts::ShutDown(){
    for(auto font : fonts){
        UnloadFont(font.second);
    }
}