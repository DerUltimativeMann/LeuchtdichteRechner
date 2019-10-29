#include "gui/application.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int iCmdShow)
{
    HWND hWindow, hModel, hData, hGraph;
    Graph g;
    GraphdataList *gdl = NULL;

    /* Test data *//*
    setGraph(&g, 0, 0, 500, 250, 100, 20);
    gdl = addGraphData(gdl, 100, 100);
    gdl = addGraphData(gdl, 1, 220);
    gdl = addGraphData(gdl, 500, 123);
    gdl = addGraphData(gdl, 200,63);
    gdl = addGraphData(gdl, 125, 12);
    gdl = addGraphData(gdl, 30, 40);
    gdl = addGraphData(gdl, 12, 210);
    */

    /* register window classes */
    if(!registerMainWnd(hInst)) return 0;
    if(!registerModelWnd(hInst)) return 0;
    if(!registerDataWnd(hInst)) return 0;
    if(!registerGraphWnd(hInst)) return 0;

    /* create windows */
    hWindow = CreateWindow(MAINWND, "ldt Calculator", WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, NULL, NULL, hInst, NULL);
    hModel = CreateWindowEx(WS_EX_CLIENTEDGE, MODELWND, NULL, WS_CHILD, 0, 0, 0, 0, hWindow, NULL, hInst, NULL);
    hData = CreateWindowEx(WS_EX_CLIENTEDGE, DATAWND, NULL, WS_CHILD, 0, 0, 0, 0, hWindow, NULL, hInst, NULL);
    hGraph = CreateWindowEx(WS_EX_CLIENTEDGE, GRAPHWND, NULL, WS_CHILD, 0, 0, 0, 0, hWindow, NULL, hInst, NULL);

    /* link child windows to main window */
    SendMessage(hWindow, APPMSG_GETCHILDWNDMODEL, 0, (LPARAM)hModel);
    SendMessage(hWindow, APPMSG_GETCHILDWNDDATA, 0, (LPARAM)hData);
    SendMessage(hWindow, APPMSG_GETCHILDWNDGRAPH, 0, (LPARAM)hGraph);

    /* setup windows */
    SendMessage(hGraph, APPMSG_SETUPGRAPH, (WPARAM)gdl, (LPARAM)&g);

    /* update */
    UpdateWindow(hWindow);

    if(hWindow && hModel && hData && hGraph)
    {
        MSG msg;

        /* run program... */
        while(GetMessage(&msg, NULL, 0, 0) != 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    /* destroy windows */
    DestroyWindow(hGraph);
    DestroyWindow(hData);
    DestroyWindow(hModel);
    DestroyWindow(hWindow);

    /* delete data */
    deleteGraphDataList(gdl);

    return 0;
}
