#include "menu.hpp"
#include <iostream>

// Options return functions
void StartGameF(){
    std::cout << "Start Game" << '\n';
}
void LoadGameF(){
    std::cout << "Load Game" << '\n';
}
void OptionsGameF(GameState& state){
    state = GameState::OPTIONS;
}
void ExitGameF(){
    CloseWindow();
}

Menu::Menu()
{
    cursorPosition = 0;
    options = {"Iniciar Jogo", "Carregar Jogo", "Opções", "Sair"};
}

//Update the menu
void Menu::Update(GameState& state)
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
            case StartGame: StartGameF(); break;
            case LoadGame: LoadGameF(); break;
            case Option: OptionsGameF(state); break;
            case Exit: ExitGameF(); break;
            default: break;
        }
    }
}
void Menu::Draw()
{
   //Drawing options
   for(int i = 0; i < options.size(); i++){
    DrawText(options[i].c_str(), OPTION_X_POSITION_MENU, OPTION_Y_POSITION_MENU + i * OPTION_Y_DISTANCE_MENU, OPTION_FONT_SIZE_MENU, (cursorPosition == i ? OPTION_SELECTED_COLOR_MENU : OPTION_NON_SELECTED_COLOR_MENU));
   if(cursorPosition == i){
        Vector2 arrowSize = MeasureTextEx(GetFontDefault(), ">", 20, 0);
        DrawTextEx(GetFontDefault(), ">", {(float)(OPTION_X_POSITION_MENU - arrowSize.x), (float)(OPTION_Y_POSITION_MENU + i * OPTION_Y_DISTANCE_MENU)}, 20, 0, OPTION_SELECTED_COLOR_MENU);}
    }
}
//Return the selected option
MenuOption Menu::GetSelectedOption()
{
    return static_cast<MenuOption>(cursorPosition);
}