#include <stdio.h>
#include <math.h>
float a, b, c;
int solver( float, float, float, float *, float *);
int vvod(float *, float *, float *);
int vyvod(int, int, float, float );
int vyvod(int, int, float , float );
int main(void)
 {
    printf("enter the coefficients of the quadratic equation\n");
    float x = 0, y = 0;
    float a = 0, b = 0, c =0;
    float *pa = &a;
    float *pb = &b;
    float *pc = &c;
    float *px = &x;
    float *py = &y;
    int ar = vvod(&a, pb, pc);
    int n_roots = solver(a, b, c, px, py);
    vyvod(ar, n_roots, x, y);
    return 0;
}
int solver(float a, float b, float c, float *px,float *py)
{
    float d = 0;
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
int vvod(float *pa, float *pb, float *pc)
{
    float a = 0, b = 0, c = 0;
    int sca = 0, scb = 0, scc = 0;
    sca = scanf("%f", &a);
    scb = scanf("%f", &b);
    scc = scanf("%f", &c);
    *pa = a;
    *pb = b;
    *pc = c;
    /*printf("%f, %f, %f", a, b, c);*/
    if ((sca == 0) || (scb == 0) || (scc == 0))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int vyvod(int ar, int n_roots, float x, float y)
{
    if (ar == 0)
    {
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
    }
    else
    {
        printf("write numbers instead of words");
    }
    return 0;
}
