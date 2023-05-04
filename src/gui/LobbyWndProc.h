#include <Kener.h>

class LobbyWndProc:public DefWndProc<LobbyWndProc>
{
protected:
    HWND startServerButton;
public:
    static PCTSTR getClassName()
    {
        return TEXT("KenerLobby");
    }
    LobbyWndProc(Window<LobbyWndProc> *window):DefWndProc(window)
    {
    }
    void onOpen();
    LRESULT onCreate(WPARAM wParam,LPARAM lParam);
    LRESULT onSize(WPARAM wParam,LPARAM lParam);
    LRESULT onPaint(WPARAM wParam,LPARAM lParam);
};
