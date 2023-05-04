class GameWndProc:public DefWndProc<GameWndProc>
{
protected:
    Window<MapWndProc> mapWindow;
public:
    static PCTSTR getClassName()
    {
        return TEXT("KenerGame");
    }
    GameWndProc(Window<GameWndProc> *window):DefWndProc(window)
    {
    }
    void onOpen();
    LRESULT onCreate(WPARAM wParam,LPARAM lParam);
};
