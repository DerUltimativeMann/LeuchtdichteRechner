#include <windows.h>

LRESULT CALLBACK mainWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch(msg)
    {
        case WM_CREATE:
        MoveWindow(hwnd, 20, 20, 800, 640, TRUE);
        ShowWindow(hwnd, SW_SHOW);
        return 0;

        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int iCmdShow)
{
    /* register window classes
    */
    WNDCLASS wndc;
    HWND hWindow;

    wndc.cbClsExtra = 0;
    wndc.cbWndExtra = 0;
    wndc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndc.hInstance = hInst;
    wndc.lpfnWndProc = mainWndProc;
    wndc.lpszClassName = "main_Window";
    wndc.lpszMenuName = NULL;
    wndc.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClass(&wndc)) return 0;

    hWindow = CreateWindow("main_Window", "ldt Calculator", WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, NULL, NULL, hInst, NULL);
    if(hWindow)
    {
        MSG msg;

        while(GetMessage(&msg, NULL, 0, 0) != 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }


    return 0;
}
