#include "application.h"

/* Registry
*/
int registerDataWnd(HINSTANCE hInstance)
{
    WNDCLASS wndc;

    wndc.cbClsExtra = 0;
    wndc.cbWndExtra = 0;
    wndc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndc.hInstance = hInstance;
    wndc.lpfnWndProc = dataWndProc;
    wndc.lpszClassName = DATAWND;
    wndc.lpszMenuName = NULL;
    wndc.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClass(&wndc)) return 0;
    return 1;
}

/* Callback function
*/
LRESULT CALLBACK dataWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch(msg)
    {
        case WM_PAINT:
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

