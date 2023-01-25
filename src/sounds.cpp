#include "sounds.hpp"

std::unordered_map<std::string, Sound> Audio::sounds;

std::vector<std::string> SoundsPath{"../res/sounds/click.mp3"};

void Audio::Load(std::string name, std::string filepath){
    Sound sound = LoadSound(filepath.c_str());
    sounds[name] = sound;
}

Sound Audio::GetSound(const std::string& soundName)
{
    return sounds[soundName];
}

void Audio::Init(){
    InitAudioDevice();
    for(int i; i<SoundsPath.size(); i++){
        Load(GetFileNameWithoutExt(SoundsPath[i].c_str()), SoundsPath[i]);
    }
}

void Audio::ShutDown(){
    for(auto x : sounds){
        UnloadSound(x.second);
    }
}