#ifndef _VECTORMATH_H
#define _VECTORMATH_H

typedef struct
{
    double x1;
    double x2;
    double x3;
}vec3;

typedef struct
{
    vec3 v1;
    vec3 v2;
}Plain;

void normalize(vec3 *);

#endif
