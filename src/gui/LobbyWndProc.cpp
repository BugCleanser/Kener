#include <Kener.h>


void LobbyWndProc::onOpen()
{
    SetClassLongPtr(window->hWnd,GCLP_HBRBACKGROUND,(LONG_PTR)CreateSolidBrush(RGB(0,0,255)));
}
LRESULT LobbyWndProc::onCreate(WPARAM wParam,LPARAM lParam)
{
    startServerButton=window->createButton(TEXT("Start Server"),256,256,128,64,[&](HWND hWnd,int bn,int extra)
    {

    });
    return DefWndProc::onCreate(wParam,lParam);
}
LRESULT LobbyWndProc::onSize(WPARAM wParam,LPARAM lParam)
{
    MoveWindow(startServerButton,256,256,128,64,TRUE);
    return DefWndProc::onSize(wParam,lParam);
}
LRESULT LobbyWndProc::onPaint(WPARAM wParam,LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc=BeginPaint(window->hWnd,&ps);
    SetBkMode(hdc,TRANSPARENT);
    SetTextColor(hdc,RGB(255,255,255));
    HFONT hFont=CreateFont(64,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,TEXT("Arial"));
    SelectObject(hdc,hFont);
    PCTSTR text=TEXT("Hello, World!");
    TextOut(hdc,256,128,text,tcslen(text));
    DeleteObject(hFont);
    EndPaint(window->hWnd,&ps);
    return 0;
}
