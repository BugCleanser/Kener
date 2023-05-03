#include <Kener.h>

void ClientWndProc::onOpen()
{
    activeWindow=gameWindow.open(TEXT("Game"),WS_CHILD,window->hWnd);
}
LRESULT ClientWndProc::onCreate(WPARAM wParam,LPARAM lParam)
{
    return DefWndProc::onCreate(wParam,lParam);
}
LRESULT ClientWndProc::onSize(WPARAM wParam,LPARAM lParam)
{
    assert((bool)IsWindow(activeWindow));
    MoveWindow(activeWindow,0,0,LOWORD(lParam),HIWORD(lParam),TRUE);
    return DefWndProc::onSize(wParam,lParam);
}
LRESULT ClientWndProc::onDestroy(WPARAM wParam,LPARAM lParam)
{
    PostQuitMessage(0);
    return 0;
}
