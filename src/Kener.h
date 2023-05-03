#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <functional>
#include <thread>
#include <assert.h>

#include <winsock2.h>
#include <Windows.h>
#include <windowsx.h>
#include <uxtheme.h>

#include <commctrl.h>
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
#include <core/Core.h>
#include <gui/Gui.h>
