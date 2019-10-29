#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    double angle;
    double value;
}TabData;

int main(int argc, char **argv)
{
    FILE *fp = fopen("sintab.dat", "wb");
    TabData td;
    int i;
    const double PI = 3.14159265359;

    for(i=0; i<360; i++)
    {
        td.angle = 2*PI/360 * i;
        td.value = sin(td.angle);
        fwrite(&td, sizeof(TabData), 1, fp);
    }
    fclose(fp);

    /* sintab tb
    if((fp = fopen("sintab.dat", "rb")))
    {
        for(i=0; i<360; i++)
        {
            fread(&td, sizeof(TabData), 1, fp);
            if(i%20 == 0)printf("sin(%.2lf) = %.3lf\n", td.angle * 360 / 2 / PI, td.value);
        }
        fclose(fp);
    }
    */


    return 0;
}
