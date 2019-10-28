#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <windows.h>

/* Application messages */
#define APPMSG_GETCHILDWNDMODEL     WM_APP + 1
#define APPMSG_GETCHILDWNDDATA      WM_APP + 2

/* Class identifier */
#define MAINWND     "app_SeN_mainwnd"
#define MODELWND    "app_SeN_modelwnd"
#define DATAWND     "app_SeN_datawnd"

/* Registry */
int registerMainWnd(HINSTANCE);
int registerModelWnd(HINSTANCE);
int registerDataWnd(HINSTANCE);

/* Callback functions */
LRESULT CALLBACK mainWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK modelWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK dataWndProc(HWND, UINT, WPARAM, LPARAM);

#endif
