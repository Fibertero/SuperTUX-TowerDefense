#include"options.hpp"


OptionsMenu::OptionsMenu(){
    cursorPosition = 0;
    options = {"Volume", "Max FPS"};
}

Options OptionsMenu::GetSelectedOption(){
    return static_cast<Options>(cursorPosition);
}


void OptionsMenu::Draw()
{
    //Drawing the main game text in menu
   DrawText("Options", TITLE_X_POSITION_OPTIONS, TITLE_Y_POSITION_OPTIONS, TITLE_FONT_SIZE_OPTIONS, TITLE_COLOR_OPTIONS);
   //Drawing options
   for(int i = 0; i < options.size(); i++){
    DrawText(options[i].c_str(), 150, OPTION_Y_POSITION_OPTIONS + i * OPTION_Y_DISTANCE_OPTIONS, OPTION_FONT_SIZE_OPTIONS, (cursorPosition == i ? OPTION_SELECTED_COLOR_OPTIONS : OPTION_NON_SELECTED_COLOR_OPTIONS));
   if(cursorPosition == i){
        Vector2 arrowSize = MeasureTextEx(GetFontDefault(), ">", 20, 0);
        DrawTextEx(GetFontDefault(), ">", {(float)(150 - arrowSize.x), (float)(OPTION_Y_POSITION_OPTIONS + i * OPTION_Y_DISTANCE_OPTIONS)}, 20, 0, OPTION_SELECTED_COLOR_OPTIONS);
        }
    }
}

void OptionsMenu::Update()
{
    //Change the cursor position
    if (IsKeyPressed(KEY_DOWN)) cursorPosition++;
    if (IsKeyPressed(KEY_UP)) cursorPosition--;


    //Limit the options that can be choosen
    if (cursorPosition < 0) cursorPosition = options.size() - 1;
    if (cursorPosition >= options.size()) cursorPosition = 0;

    // Get the option clicked
    if (IsKeyPressed(KEY_ENTER))
    {
        switch (cursorPosition)
        {
            case MAXFPS: ; break;
            case VOLUME: ; break;
            default: break;
        }
    }
}