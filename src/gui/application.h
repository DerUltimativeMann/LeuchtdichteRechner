#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <windows.h>

/* Application messages */
#define APPMSG_GETCHILDWNDMODEL     WM_APP + 1
#define APPMSG_GETCHILDWNDDATA      WM_APP + 2
#define APPMSG_GETCHILDWNDGRAPH     WM_APP + 3

/* Class identifier */
#define MAINWND     "app_SeN_mainwnd"
#define MODELWND    "app_SeN_modelwnd"
#define DATAWND     "app_SeN_datawnd"
#define GRAPHWND    "app_SeN_graphwnd"

/* Registry */
int registerMainWnd(HINSTANCE);
int registerModelWnd(HINSTANCE);
int registerDataWnd(HINSTANCE);
int registerGraphWnd(HINSTANCE);

/* Callback functions */
LRESULT CALLBACK mainWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK modelWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK dataWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK graphWndProc(HWND, UINT, WPARAM, LPARAM);

#endif
