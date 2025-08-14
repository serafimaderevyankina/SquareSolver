#include <stdio.h>
#include <math.h>
int main(void)
{
    float a, b, c, d, x, y;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    d = x = y = 0;
    d = b*b - 4.0f*(a*c);
    /*printf("%f\n", d);*/
    if (a == 0)
    {
        if (b == 0)
        {
            printf(" no sense");
        }
        else
        {
            x = (-c/b);
            printf("%f", x);
         }
    }
    else if ( a != 0 && d < 0)
    {
           printf("no x \n");
    }
    else if ( a != 0 && d > 0)
    {
        x = ((-b - sqrt(d))/2.0f)/a;
        y = ((-b + sqrt(d))/2.0f)/a;
        printf("%f, %f, %f, %f", x, y, d, a);
    }
    else if (a != 0 && d == 0)
    {
        x  = -b/ (2.0f*a);
        printf("%f", x);
    }
    return 0;
}
