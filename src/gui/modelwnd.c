#include "application.h"

/* Registry
*/
int registerModelWnd(HINSTANCE hInstance)
{
    WNDCLASS wndc;

    wndc.cbClsExtra = 0;
    wndc.cbWndExtra = 0;
    wndc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndc.hInstance = hInstance;
    wndc.lpfnWndProc = modelWndProc;
    wndc.lpszClassName = MODELWND;
    wndc.lpszMenuName = NULL;
    wndc.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClass(&wndc)) return 0;
    return 1;
}

/* Callback function
*/
LRESULT CALLBACK modelWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch(msg)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            int i;

            for(i=0; i < 20; i++) Rectangle(hdc, 10 + i*4, 10 + i*4, 40 + i*4, 40 + i*4);
            EndPaint(hwnd, &ps);
        }
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

