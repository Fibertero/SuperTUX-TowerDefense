#include "textures.hpp"
#include<iostream>
std::unordered_map<std::string, Texture2D> textures;

std::vector<std::string> texturesPath{"../res/images/background.png", "../res/images/background2.png", "../res/images/castle.png"};

void Textures::Load(std::string name, std::string filePath) {
    Texture2D texture = LoadTexture(filePath.c_str());
    textures[name] = texture;
}

Texture2D& Textures::Get(std::string name) {
    return textures[name];
}

void Textures::ShutDown() {
    for (auto& texture : textures) {
        UnloadTexture(texture.second);
    }
    textures.clear();
}

void Textures::Init(){
    for(int i; i<texturesPath.size(); i++){
        Load(GetFileNameWithoutExt(texturesPath[i].c_str()), texturesPath[i]);
    }
}