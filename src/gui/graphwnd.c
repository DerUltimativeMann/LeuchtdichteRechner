#include "application.h"

/* Registry
*/
int registerGraphWnd(HINSTANCE hInstance)
{
    WNDCLASS wndc;

    wndc.cbClsExtra = 0;
    wndc.cbWndExtra = 0;
    wndc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndc.hInstance = hInstance;
    wndc.lpfnWndProc = graphWndProc;
    wndc.lpszClassName = GRAPHWND;
    wndc.lpszMenuName = NULL;
    wndc.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClass(&wndc)) return 0;
    return 1;
}

/* Callback function
*/
LRESULT CALLBACK graphWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    static Graph *gp;
    static GraphdataList *gdl;

    switch(msg)
    {
        case APPMSG_SETUPGRAPH:
        gp = (Graph*)lp;
        gdl = (GraphdataList*)wp;
        case WM_PAINT:
        if(gp)
        {
            PAINTSTRUCT ps;
            HDC hdc;
            RECT rect;
            int x0 = 20, y0 = 20, i = 0;
            int width, height, dx, dy;
            double delta;

            GetWindowRect(hwnd, &rect);

            width = rect.right - rect.left - 2*x0;
            height = rect.bottom - rect.top - 2*y0;
            dx = width / ((gp->xmax - gp->xmin) / gp->dx);
            dy = height / ((gp->ymax - gp->ymin) / gp->dy);

            hdc = BeginPaint(hwnd, &ps);

            /* draw axes */
            /* x-axis */
            MoveToEx(hdc, x0, height + y0, NULL);
            LineTo(hdc, rect.right - rect.left - x0, height + y0);

            for(delta = gp->xmin; delta < gp->xmax; delta += gp->dx)
            {
                MoveToEx(hdc, x0 + dx * i, height + y0, NULL);
                LineTo(hdc, x0 + dx * i, height + y0 + 4);
                i++;
            }

            /* y-axis */
            MoveToEx(hdc, x0, height + y0, NULL);
            LineTo(hdc, x0, y0);
            i = 0;
            for(delta = gp->ymin; delta < gp->ymax; delta += gp->dy)
            {
                MoveToEx(hdc, x0 - 4, height + y0 - dy * i, NULL);
                LineTo(hdc, x0, height + y0 - dy * i);
                i++;
            }

            /* draw graph */
            if(gdl)
            {
                GraphdataList *temp = gdl;
                HPEN redpen = (HPEN)SelectObject(hdc,CreatePen(0,0, RGB(255,10, 10)));
                while(temp)
                {
                    if(temp == gdl) MoveToEx(hdc, x0 + temp->data.x * width / (gp->xmax - gp->xmin), height + y0 - temp->data.y * height / (gp->ymax - gp->ymin), NULL);
                    else LineTo(hdc, x0 + temp->data.x * width / (gp->xmax - gp->xmin), height + y0 - temp->data.y * height / (gp->ymax - gp->ymin));
                    temp = temp->next;
                }
                DeleteObject(redpen);
            }

            EndPaint(hwnd, &ps);
        }
        return 0;

        case WM_CLOSE:
        gp = NULL;
        gdl = NULL;
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

