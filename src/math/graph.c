#include "../gui/application.h"

void setGraph(Graph *graph, double xmin, double ymin, double xmax, double ymax, double dx, double dy)
{
    if(graph)
    {
        graph->xmin = xmin;
        graph->ymin = ymin;
        graph->xmax = xmax;
        graph->ymax = ymax;
        graph->dx = dx;
        graph->dy = dy;
    }
}

void setGraphdata(Graphdata *data, double x, double y)
{
    if(data)
    {
        data->x = x;
        data->y = y;
    }
}

GraphdataList *addGraphData(GraphdataList *gdl, double x, double y)
{
    GraphdataList *pRet, *temp = gdl;

    pRet = (GraphdataList*)malloc(sizeof(GraphdataList));
    pRet->data.x = x;
    pRet->data.y = y;

    if(!gdl)
    {
        pRet->next = NULL;
    }
    else
    {
        while(temp && temp->data.x < x) temp = temp->next;

        if(temp == gdl)
        {
            pRet->next = gdl;
        }
        else if(temp)
        {
            GraphdataList *swapData = gdl;
            while(swapData->next != temp) swapData = swapData->next;
            pRet->next = temp;
            swapData->next = pRet;
            pRet = gdl;
        }
        else
        {
            for(temp = gdl; temp->next; temp = temp->next);
            temp->next = pRet;
            pRet->next = NULL;
            pRet = gdl;
        }
    }
    return pRet;
}

int deleteGraphDataList(GraphdataList *gdl)
{
    int iRet = 0;
    GraphdataList *temp = gdl, *kill;

    while(temp)
    {
        kill = temp;
        temp = temp->next;
        free(kill);
        iRet++;
    }
    return iRet;
}
