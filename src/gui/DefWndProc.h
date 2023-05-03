template<class WndProc> class DefWndProc
{
protected:
    Window<WndProc> *window;
public:
    DefWndProc(Window<WndProc> *window)
    {
        this->window=window;
    }
    void onOpen()
    {
    }
    LRESULT onCreate(WPARAM wParam,LPARAM lParam)
    {
        return DefWindowProc(window->hWnd,WM_CREATE,wParam,lParam);
    }
    LRESULT onPaint(WPARAM wParam,LPARAM lParam)
    {
        return DefWindowProc(window->hWnd,WM_PAINT,wParam,lParam);
    }
    LRESULT onSize(WPARAM wParam,LPARAM lParam)
    {
        return DefWindowProc(window->hWnd,WM_SIZE,wParam,lParam);
    }
    LRESULT onDestroy(WPARAM wParam,LPARAM lParam)
    {
        return DefWindowProc(window->hWnd,WM_DESTROY,wParam,lParam);
    }
    LRESULT onMouseWheel(WPARAM wParam,LPARAM lParam)
    {
        return DefWindowProc(window->hWnd,WM_MOUSEWHEEL,wParam,lParam);
    }
    LRESULT onOtherMessage(UINT msg,WPARAM wParam,LPARAM lParam)
    {
        return DefWindowProc(window->hWnd,msg,wParam,lParam);
    }
};