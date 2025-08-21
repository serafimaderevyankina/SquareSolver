#include <stdio.h>
#include <math.h>
float a, b, c;
int solver( float *, float *);
int main(void)
{
    float x, y = 0;
    float *px = &x;
    float *py = &y;
    solver(px, py);
    printf("%f, %f", x,y);
    return 0;
}
int solver(float *px,float *py)
{
    float a, b, c, d;
    scanf("%f", a);
    scanf("%f", b);
    scanf("%f", c);
    printf("%f, %f, %f\n", a, b, c);
    d = b*b - 4.0f*(a*c);
    /*printf("%f\n", d);*/
    if (a == 0)
    {
        if (b == 0)
        {
            printf("no sense");
        }
        else
        {
            *px = (-c/b);
            *py = (-c/b);
         }
    }
    else if ( a != 0 && d < 0)
    {
           printf( "no sense");
    }
    else if ( a != 0 && d > 0)
    {
        *px = ((-b - sqrt(d))/2.0f)/a;
        *py = ((-b + sqrt(d))/2.0f)/a;

    }
    else if (a != 0 && d == 0)
    {
        *px  = -b/ (2.0f*a);
        *py = -b/ (2.0f*a);
    }
    return 0;
}
