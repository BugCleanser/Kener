#include <Kener.h>

void MapWndProc::onOpen()
{
    SetClassLongPtr(window->hWnd,GCLP_HBRBACKGROUND,(LONG_PTR)CreateSolidBrush(RGB(0,255,0)));
}
