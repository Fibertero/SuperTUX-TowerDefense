#include"options.hpp"
#include<iostream>

static void VolumeF(float& volume, float quantity){
    //Adding the quantity to the volume
    if((volume+quantity)<1.1 && (volume+quantity)>0) volume+=quantity;
    //Updating the volume variable
    SetMasterVolume(volume);
}
static void DrawFpsF(bool& drawFps){
    if(drawFps) drawFps = false;
    else drawFps = true;
}
static void FullScreenF(){
    ToggleFullscreen();
}


OptionsMenu::OptionsMenu(){
    cursorPosition = 0;
    options = {"Volume", "DrawFPS", "FullScreen"};

    /*Adding basic config to the booleans hashmap*/
    globalBooleans.insert(std::pair<std::string, bool>("DrawFPS", false));
}

Options OptionsMenu::GetSelectedOption(){
    return static_cast<Options>(cursorPosition);
}


void OptionsMenu::Draw(float& volume, Font textFont)
{
    //Drawing the main game text in menu
   DrawTextEx(textFont, "Options", {TITLE_X_POSITION_OPTIONS, TITLE_Y_POSITION_OPTIONS}, TITLE_FONT_SIZE_OPTIONS, 0, TITLE_COLOR_OPTIONS);
   //Drawing options
   for(int i = 0; i < options.size(); i++){
    DrawTextEx(textFont, options[i].c_str(), (Vector2){OPTION_X_POSITION_OPTIONS, OPTION_Y_POSITION_OPTIONS + i * OPTION_Y_DISTANCE_OPTIONS}, OPTION_FONT_SIZE_OPTIONS, 0, (cursorPosition == i ? OPTION_SELECTED_COLOR_OPTIONS : OPTION_NON_SELECTED_COLOR_OPTIONS));
   if(cursorPosition == i){
        Vector2 arrowSize = MeasureTextEx(GetFontDefault(), ">", 20, 0);
        DrawTextEx(GetFontDefault(), ">", {(float)(150 - arrowSize.x), (float)(OPTION_Y_POSITION_OPTIONS + i * OPTION_Y_DISTANCE_OPTIONS)}, 20, 0, OPTION_SELECTED_COLOR_OPTIONS);
        }
    }
    //Drawing the current volume value
    DrawText(std::to_string(static_cast<int>(volume*10)).c_str(), OPTION_X_POSITION_OPTIONS+DISTANCE_OPTION_PREVIEW, OPTION_Y_POSITION_OPTIONS /*OPTION_Y_DISTANCE_OPTIONS*/, 20, WHITE);
    //Drawing the drawFPS condition
    DrawText((globalBooleans["DrawFPS"]) ? "On" : "Off", OPTION_X_POSITION_OPTIONS+DISTANCE_OPTION_PREVIEW+10, OPTION_Y_POSITION_OPTIONS + OPTION_Y_DISTANCE_OPTIONS, 20, (globalBooleans["DrawFPS"]) ? GREEN : RED);
    DrawText((IsWindowFullscreen()) ? "On" : "Off", OPTION_X_POSITION_OPTIONS+DISTANCE_OPTION_PREVIEW+30, OPTION_Y_POSITION_OPTIONS + 2 * OPTION_Y_DISTANCE_OPTIONS, 20, (IsWindowFullscreen()) ? GREEN : RED);
}

void OptionsMenu::Update(float& volume, GameState& gameState)
{
    //Change the cursor position
    if (IsKeyPressed(KEY_DOWN)) cursorPosition++;
    if (IsKeyPressed(KEY_UP)) cursorPosition--;


    //Limit the options that can be choosen
    if (cursorPosition < 0) cursorPosition = options.size() - 1;
    if (cursorPosition >= options.size()) cursorPosition = 0;

    // Getting arrow pressed to update the values. LEFT = "-", RIGHT = "+"
    if (IsKeyPressed(KEY_RIGHT))
    {
        switch (cursorPosition)
        {
            case VOLUME: VolumeF(volume, 0.1); break;
            case DRAWFPS: DrawFpsF(globalBooleans["DrawFPS"]); break;
            case FULLSCREEN: FullScreenF(); break;
            default: break;
        }
    }
    else if (IsKeyPressed(KEY_LEFT)){
        switch (cursorPosition)
        {
            case VOLUME: VolumeF(volume, -0.1); break;
            case DRAWFPS: DrawFpsF(globalBooleans["DrawFPS"]); break;
            case FULLSCREEN: FullScreenF(); break;
            default: break;
        }
    }

    if(IsKeyPressed(KEY_ESCAPE)){
        gameState = MENU;
    }


}