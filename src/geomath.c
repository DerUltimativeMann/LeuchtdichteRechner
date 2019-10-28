#include "geomath.h"

int setData3d(Data3d *data, double x1, double x2, double x3)
{
    if(data)
    {
        data->x1 = x1;
        data->x2 = x2;
        data->x3 = x3;
        return 1;
    }
    return 0;
}
