#include <Kener.h>

void GameWndProc::onOpen()
{
    SetClassLongPtr(window->hWnd,GCLP_HBRBACKGROUND,(LONG_PTR)CreateSolidBrush(RGB(255,0,0)));
    mapWindow.open(TEXT("Map"),WS_CHILD,window->hWnd,128,128,256,256);
}
