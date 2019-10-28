#include "lightbody.h"

int setBodyCube(BodyCube *bc, double width, double height, double length)
{
    if(bc)
    {
        bc->width = width;
        bc->height = height;
        bc->length = length;
        return 1;
    }
    return 0;
}

int setBodyRound(BodyRound *br, double radius, double height)
{
    if(br)
    {
        br->radius = radius;
        br->height = height;
        return 1;
    }
    return 0;
}
