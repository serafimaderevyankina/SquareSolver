#include <stdio.h>
#include <math.h>
float a, b, c;
int solver( float *, float *);
int main(void)
 {
    printf("enter the coefficients of the quadratic equation");
    float x = 0, y = 0;
    float *px = &x;
    float *py = &y;
    int n_roots = solver(px, py);
    if (n_roots == 0)
    {
        printf("no roots");
    }
    else if (n_roots == 3)
    {
        printf("infinity number of roots");
    }
    else if (n_roots == 2)
    {
    printf("solutions to the equation:%f, %f", x,y);
    }
    else if (n_roots == 1)
    {
        printf("solutions to the equation:%f", x);
    }
    else if (n_roots == 4)
    {
        printf("you are deep. Don't write words instead of numbers");
    }
    return 0;
}
int solver(float *px,float *py)
{
    float a = 0, b = 0, c = 0, d = 0;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    if (a == NULL || b == NULL || c == NULL)
    {
        return 4;
    }
    /*printf("%f, %f, %f\n", a, b, c);*/
    d = b*b - 4.0f*(a*c);
    /*printf("%f\n", d);*/
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return 3;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            *px = (-c/b);
            return 1;
         }
    }
    else if ( a != 0 && d < 0)
    {
       return 0;
    }
    else if ( a != 0 && d > 0)
    {
        *px = ((-b - sqrt(d))/2.0f)/a;
        *py = ((-b + sqrt(d))/2.0f)/a;
        return 2;

    }
    else if (a != 0 && d == 0)
    {
        *px  = -b/ (2.0f*a);
        return 1;
    }
}
