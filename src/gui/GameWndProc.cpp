#include <Kener.h>

void GameWndProc::onOpen()
{
    mapWindow.open(TEXT("Map"),WS_CHILD,window->hWnd,128,128,256,256);
    SetClassLongPtr(window->hWnd,GCLP_HBRBACKGROUND,(LONG_PTR)CreateSolidBrush(RGB(255,0,0)));
}

LRESULT GameWndProc::onCreate(WPARAM wParam,LPARAM lParam)
{
    return DefWndProc::onCreate(wParam,lParam);
}
