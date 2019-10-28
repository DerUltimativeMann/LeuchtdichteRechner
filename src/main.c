#include "gui/application.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int iCmdShow)
{
    HWND hWindow, hModel, hData;

    /* Register window classes */
    if(!registerMainWnd(hInst)) return 0;
    if(!registerModelWnd(hInst)) return 0;
    if(!registerDataWnd(hInst)) return 0;

    /* Create windows */
    hWindow = CreateWindow(MAINWND, "ldt Calculator", WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, NULL, NULL, hInst, NULL);
    hModel = CreateWindowEx(WS_EX_CLIENTEDGE, MODELWND, NULL, WS_CHILD, 0, 0, 0, 0, hWindow, NULL, hInst, NULL);
    hData = CreateWindowEx(WS_EX_CLIENTEDGE, DATAWND, NULL, WS_CHILD, 0, 0, 0, 0, hWindow, NULL, hInst, NULL);

    /* Link child windows to main window */
    SendMessage(hWindow, APPMSG_GETCHILDWNDMODEL, 0, (LPARAM)hModel);
    SendMessage(hWindow, APPMSG_GETCHILDWNDDATA, 0, (LPARAM)hData);

    if(hWindow && hModel && hData)
    {
        MSG msg;

        /* run program... */
        while(GetMessage(&msg, NULL, 0, 0) != 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    /* Destroy windows */
    DestroyWindow(hData);
    DestroyWindow(hModel);
    DestroyWindow(hWindow);

    return 0;
}
