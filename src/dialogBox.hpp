#include"raylib.h"
#define WARNING_MESSAGE RED

struct GlobalMessage
{
    const char *text;
    Color textColor;
    bool isActive;
    void (*functionAction)();
    void SetInfo(const char *_text, Color _textColor, void (*func)());
    void DrawMessage();
    void Undefine();
};