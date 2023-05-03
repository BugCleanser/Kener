#include "Kener.h"

Kener::Kener Kener::instance;

int WINAPI tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PTSTR lpCmdLine,int nCmdShow)
{
    Kener::instance.process=hInstance;
    Kener::instance.showCmd=nCmdShow;
    
    Window<ClientWndProc> window;
    window.open(TEXT("Kener"));
    window.join();

    return 0;
}
