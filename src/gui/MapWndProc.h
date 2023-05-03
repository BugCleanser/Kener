class MapWndProc:public DefWndProc<MapWndProc>
{
public:
    static PCTSTR getClassName()
    {
        return TEXT("KenerMap");
    }
    MapWndProc(Window<MapWndProc> *window):DefWndProc(window)
    {
    }
    void onOpen();
};
