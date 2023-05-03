#include <winsock2.h>
#include <Windows.h>
#include <windowsx.h>
#include <uxtheme.h>
#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <functional>
#include <thread>
#include <commctrl.h>
#include <string>
#include <utility>
#include <ws2tcpip.h>

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

#include <network/Network.h>
#include <gui/Gui.h>
