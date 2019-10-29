#include "application.h"

/* Registry
*/
int registerMainWnd(HINSTANCE hInstance)
{
    WNDCLASS wndc;

    wndc.cbClsExtra = 0;
    wndc.cbWndExtra = 0;
    wndc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
    wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndc.hInstance = hInstance;
    wndc.lpfnWndProc = mainWndProc;
    wndc.lpszClassName = MAINWND;
    wndc.lpszMenuName = NULL;
    wndc.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClass(&wndc)) return 0;
    return 1;
}

/* Callback function
*/
LRESULT CALLBACK mainWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    static HWND hModel, hData, hGraph;
    static RECT rect;

    switch(msg)
    {
        /* Application messages */
        case APPMSG_GETCHILDWNDGRAPH:
        hGraph = (HWND)lp;
        return 0;

        case APPMSG_GETCHILDWNDDATA:
        hData = (HWND)lp;
        return 0;

        case APPMSG_GETCHILDWNDMODEL:
        hModel = (HWND)lp;
        return 0;

        /* windows messages */
        case WM_PAINT:
        case WM_SIZE:
        GetWindowRect(hwnd, &rect);
        if(hGraph)
        {
            MoveWindow(hGraph, 8 + 0.3 * (rect.right - rect.left), 8, 0.5 * (rect.right - rect.left), (rect.bottom - rect.top - 60) / 2, TRUE);
            ShowWindow(hGraph, SW_SHOW);
        }
        if(hData)
        {
            MoveWindow(hData, 8, 8, 0.3 * (rect.right - rect.left), rect.bottom - rect.top - 60, TRUE);
            ShowWindow(hData, SW_SHOW);
        }
        if(hModel)
        {
            MoveWindow(hModel, 8 + 0.3 * (rect.right - rect.left), 8 + (rect.bottom - rect.top - 60) / 2, 0.5 * (rect.right - rect.left), (rect.bottom - rect.top - 60) / 2, TRUE);
            ShowWindow(hModel, SW_SHOW);
        }
        return 0;

        case WM_CREATE:
        MoveWindow(hwnd, 20, 20, 900, 640, TRUE);
        GetWindowRect(hwnd, &rect);
        ShowWindow(hwnd, SW_SHOW);
        return 0;

        case WM_DESTROY:
        hModel = NULL;
        hData = NULL;
        hGraph = NULL;
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}
