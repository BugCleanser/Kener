class ClientWndProc:public DefWndProc<ClientWndProc>
{
protected:
    Window<LobbyWndProc> lobbyWindow;
    Window<GameWndProc> gameWindow;
    HWND activeWindow;
public:
    static PCTSTR getClassName()
    {
        return TEXT("KenerClient");
    }
    ClientWndProc(Window<ClientWndProc> *window):DefWndProc(window)
    {
    }
    void onOpen();
    LRESULT onCreate(WPARAM wParam,LPARAM lParam);
    LRESULT onSize(WPARAM wParam,LPARAM lParam);
    LRESULT onDestroy(WPARAM wParam,LPARAM lParam);
};
