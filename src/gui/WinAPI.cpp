#include <Kener.h>

HFONT defaultFont;

STATIC(
{
    INITCOMMONCONTROLSEX icc={};
    icc.dwSize=sizeof(INITCOMMONCONTROLSEX);
    icc.dwICC=ICC_STANDARD_CLASSES|ICC_WIN95_CLASSES|ICC_ANIMATE_CLASS|ICC_COOL_CLASSES;
    InitCommonControlsEx(&icc);
    
    LOGFONT logFont;
    SystemParametersInfo(SPI_GETICONTITLELOGFONT,sizeof(logFont),&logFont,0);
    defaultFont=CreateFontIndirect(&logFont);
})

void setFont(HWND hWnd,HFONT hFont)
{
    SendMessage(hWnd,WM_SETFONT,(WPARAM)hFont,MAKELPARAM(TRUE,0));
}
void setDefaultFont(HWND hWnd)
{
    setFont(hWnd,defaultFont);
}
