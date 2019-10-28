#ifndef _LIGHT_BODY_H
#define _LIGHT_BODY_H

typedef struct
{
   double width;
   double height;
   double length;
}BodyCube;

typedef struct
{
    double radius;
    double height;
}BodyRound;

int setBodyCube(BodyCube *bc, double width, double height, double length);
int setBodyRound(BodyRound *br, double radius, double height);

#endif

