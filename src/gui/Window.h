#include <Kener.h>

template<class WndProc> class Window
{
protected:
    WndProc wndProc;
    std::unordered_map<HWND,std::function<void(HWND,int,int)>> buttonProcessors;
public:
    HWND hWnd;
    Window():wndProc(this)
    {
        hWnd=nullptr;
    }
    HWND open(PCTSTR title,DWORD style=WS_OVERLAPPEDWINDOW,HWND parent=nullptr,int x=CW_USEDEFAULT,int y=CW_USEDEFAULT,int width=CW_USEDEFAULT,int height=CW_USEDEFAULT)
    {
        WndProc::getClassName();
        WNDCLASSEX wc={};
        wc.cbSize=sizeof(WNDCLASSEX);
        wc.lpszClassName=WndProc::getClassName();
        wc.hInstance=Kener::instance.process;
        wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
        wc.hIcon=LoadIcon(wc.hInstance,TEXT("icon"));
        wc.hIconSm=LoadIcon(wc.hInstance,TEXT("icon"));
        wc.hCursor=LoadCursor(nullptr,IDC_ARROW);
        wc.lpfnWndProc=[](HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)->LRESULT CALLBACK
        {
            Window<WndProc> *thiz=(Window<WndProc>*)GetWindowLongPtr(hWnd,GWLP_USERDATA);
            if(msg==WM_CREATE)
            {
                thiz=(Window<WndProc>*)((CREATESTRUCT*)lParam)->lpCreateParams;
                thiz->hWnd=hWnd;
                SetWindowLongPtr(hWnd,GWLP_USERDATA,(LONG_PTR)thiz);
            }
            if(thiz)
            {
                switch(msg)
                {
                case WM_CREATE:
                    return thiz->wndProc.onCreate(wParam,lParam);
                case WM_PAINT:
                    return thiz->wndProc.onPaint(wParam,lParam);
                case WM_SIZE:
                    return thiz->wndProc.onSize(wParam,lParam);
                case WM_DESTROY:
                    return thiz->wndProc.onDestroy(wParam,lParam);
                case WM_MOUSEWHEEL:
                    return thiz->wndProc.onMouseWheel(wParam,lParam);
                case WM_COMMAND:
                    if(LOWORD(wParam)==0)
                    {
                        auto i=thiz->buttonProcessors.find((HWND)lParam);
                        if(i!=thiz->buttonProcessors.end())
                        {
                            i->second(i->first,HIWORD(wParam),0);
                            return 0;
                        }
                    }
                    break;
                case WM_CONTEXTMENU:
                    {
                        auto i=thiz->buttonProcessors.find((HWND)wParam);
                        if(i!=thiz->buttonProcessors.end())
                        {
                            i->second(i->first,BN_RBCLICK,lParam);
                            return 0;
                        }
                    }
                    break;
                }
                return thiz->wndProc.onOtherMessage(msg,wParam,lParam);
            }
            else
                return DefWindowProc(hWnd,msg,wParam,lParam);
        };
        if(GetClassInfoEx(wc.hInstance,wc.lpszClassName,&wc)==FALSE)
            RegisterClassEx(&wc);
        hWnd=CreateWindow(wc.lpszClassName,title,style,x,y,width,height,parent,nullptr,wc.hInstance,this);
        SetWindowTheme(hWnd,TEXT("Explorer"),nullptr);
        wndProc.onOpen();
        ShowWindow(hWnd,Kener::instance.showCmd);
        UpdateWindow(hWnd);
        return hWnd;
    }
    HWND createButton(PCTSTR text,int x,int y,int width,int height,bool isDefault,std::function<void(HWND,int,int)> processor)
    {
        HWND ans=CreateWindow(WC_BUTTON,text,WS_VISIBLE|WS_CHILD|BS_NOTIFY|BS_PUSHBUTTON|(isDefault?BS_DEFPUSHBUTTON:0)|BS_CENTER|BS_VCENTER,x,y,width,height,hWnd,(HMENU)0,Kener::instance.process,NULL);
        setDefaultFont(ans);
        ShowWindow(ans,SW_SHOW);
        UpdateWindow(ans);
        buttonProcessors[ans]=processor;
        return ans;
    }
    void destroyButton(HWND button)
    {
        buttonProcessors.erase(button);
        DestroyWindow(button);
    }
    void join()
    {
        if(!IsWindow(hWnd))
            return;
        MSG msg;
        while(GetMessage(&msg,nullptr,0,0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        hWnd=nullptr;
    }
    ~Window()
    {
        if(IsWindow(hWnd))
        {
            DestroyWindow(hWnd);
            join();
        }
    }
};
