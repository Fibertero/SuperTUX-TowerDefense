#include"dialogBox.hpp"

void GlobalMessage::Undefine(){
    text = "";
    textColor = WHITE;
    isActive=false;
}

void GlobalMessage::SetInfo(const char *_text, Color _textColor, void (*func)()){
    text = _text;
    textColor = _textColor;
    functionAction = func;
    isActive=true;
}

void GlobalMessage::DrawMessage(){
    /*Defining constants*/
    Vector2 textSize = MeasureTextEx(GetFontDefault(), text, 20, 2);
    Vector2 screenCenter = { GetScreenWidth() / 2, GetScreenHeight() / 2};
    Rectangle DoneButton = {GetScreenWidth()-100, GetScreenHeight()-50, 80, 40};
    Rectangle CancelButton = {GetScreenWidth()-220, DoneButton.y, 120, 40};

    if(isActive){
        /*Drawing "Done Button" box*/
        DrawRectangleRec(DoneButton, GREEN);
        /*Drawing "Done Button" text*/
        DrawText("OK", DoneButton.x+25, DoneButton.y+10, 25, BLACK);
        /*Drawing "cancel button" box*/
        DrawRectangleRec(CancelButton, GRAY);
        /*Drawing "Cancel Button" text*/
        DrawText("Cancel", CancelButton.x+20, CancelButton.y+10, 25, BLACK);


        if(CheckCollisionPointRec(GetMousePosition(), DoneButton) && IsMouseButtonPressed(0)){
            functionAction();
        }
        else if(CheckCollisionPointRec(GetMousePosition(), CancelButton) && IsMouseButtonPressed(0)){
            Undefine();
        }

        /*Drawing text BOX*/
        DrawRectangle(0,500, 800, 200, ColorAlpha(GRAY, 0.5f));
        /*Drawing text INSIDE THE BOX*/
        DrawText(text, (screenCenter.x - textSize.x / 2) , (screenCenter.y - textSize.y / 2)+250, 20, textColor);
    }
}