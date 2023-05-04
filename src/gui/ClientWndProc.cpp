#include <Kener.h>

void ClientWndProc::onOpen()
{
    activeWindow=lobbyWindow.open(TEXT("Lobby"),WS_CHILD|WS_VISIBLE,window->hWnd);
    ShowWindow(gameWindow.open(TEXT("Game"),WS_CHILD|WS_VISIBLE,window->hWnd),SW_HIDE);
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
