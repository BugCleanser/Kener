#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <functional>
#include <thread>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <uxtheme.h>

#ifdef UNICODE
    #define tWinMain wWinMain
#else
    #define tWinMain WinMain
#endif

#define STATIC(code) static struct STATIC{STATIC()code}STATIC;

extern HFONT defaultFont;
namespace Kener
{
    class Kener
    {
    public:
        HINSTANCE process=NULL;
        int showCmd;
    };
    extern Kener instance;
};

#include "WinAPI.h"
#include "Window.h"
#include "DefWndProc.h"
#include "MapWndProc.h"
#include "GameWndProc.h"
#include "ClientWndProc.h"
