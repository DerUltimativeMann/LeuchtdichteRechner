#ifndef _GRAPH_H
#define _GRAPH_H

typedef struct
{
    double xmin, ymin;
    double xmax, ymax;
    double dx, dy;
}Graph;

typedef struct
{
    double x, y;
}Graphdata;

typedef struct GraphdataList_t
{
    Graphdata data;
    struct GraphdataList_t *next;
}GraphdataList;

void setGraph(Graph*, double, double, double, double, double, double);
void setGraphdata(Graphdata *, double, double);
GraphdataList *addGraphData(GraphdataList*, double, double);
int deleteGraphDataList(GraphdataList*);

#endif
