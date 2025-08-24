#include <stdio.h>
#include <math.h>
int quadsolver( float, float, float, float *, float *);
int linesolver(float, float, float *, float *);
int input(float *, float *, float *);
int output(int, float , float );
int SolveEquation(float a, float b, float c, float* px, float* py);
int testsolve(void);


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
    int vv = input(pa, pb, pc);
    int n_roots = SolveEquation(a, b, c, &x, &y);
    testsolve();
    output(n_roots, x, y);
    return 0;
}


int SolveEquation(float a, float b, float c, float* px, float* py) {
        int n = 0;
        if (a == 0) {
            n = linesolver(b, c, px, py);
        }
        else {
            n = quadsolver(a, b, c, px, py);
        }
    return n;
}


int quadsolver(float a, float b, float c, float *px,float *py)
{
    float d = 0;
    /*printf("%f, %f, %f\n", a, b, c);*/
    d = b*b - 4.0f*(a*c);
    /*printf("%f\n", d);*/
    if ( a != 0 && d < 0)
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
    else if (a == 0)
    {
        return 3;
    }
}



int linesolver(float b, float c, float *px, float *py)
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
        *px = -c/b;
        return 1;
    }
}


int input(float *pa, float *pb, float *pc)
{
    float a = 0, b = 0, c = 0;
    int sca = 0, scb = 0, scc = 0;
    sca = scanf("%f", &a);
    scb = scanf("%f", &b);
    scc = scanf("%f", &c);
    /*printf("%f, %f, %f", a, b, c);*/
    while (sca==0 || scb == 0 || scc == 0)
    {
        while ( getchar() != '\n' );
        printf("Invalid input");
        sca = scanf("%f", &a);
        scb = scanf("%f", &b);
        scc = scanf("%f", &c);
    }
    *pa = a;
    *pb = b;
    *pc = c;
    return 0;
}
int output(int n_roots, float x, float y)
{
    if (n_roots == 3)
    {
        printf("an infinite number of roots");
    }
    if (n_roots == 2)
    {
        printf("the roots is: %g,%g", x, y);
    }
    if (n_roots == 1)
    {
        printf("the root is %g", x);
    }
    if (n_roots == 0)
    {
        printf("I've got no roots");
    }
    return 0;
}


int testsolve(void)
{
    float x1 = 0, x2  = 0;
    int nroots = SolveEquation(1, -5, 6, &x1, &x2);
    if (!(nroots == 2 && x1 == 2 && x2 == 3))
    {
        printf("1 failled: x1 = %lf, x2 = %lf (should be x1 = 2, x2 = 3)",x1, x2);
    }
    x1 = 0;
    x2 = 0;
    nroots = SolveEquation(1, 2, 1, &x1, &x2);
    if (!(nroots == 1 && x1 == -1 && x2 == 0))
    {
        printf("2 failled: x1 = %lf, x2 = %lf (should be x1 = -1, x2 = nope)",x1, x2);
    }
    x1 = 0;
    x2 = 0;
    nroots = SolveEquation(0, 2, 1, &x1, &x2);
    if (!(nroots == 1 && x1 == -0,5 && x2 == 0))
    {
        printf("3 failled: x1 = %lf, x2 = %lf (should be x1 = -0,5, x2 = nope)",x1, x2);
    }
    x1 = 0;
    x2 = 0;
    nroots = SolveEquation(0, 0, 0, &x1, &x2);
    if (!(nroots == 3 && x1 == 0 && x2 == 0))
    {
        printf("4 failled: x1 = %lf, x2 = %lf (should be x1 = nope, x2 = nope)",x1, x2);
    }
    x1 = 0;
    x2 = 0;
    nroots = SolveEquation(2, 5, 3, &x1, &x2);
    if (!(nroots == 2 && x1 == -1,5 && x2 == -1))
    {
        printf("failled: x1 = %lf, x2 = %lf (should be x1 = -1,5, x2 = -1)",x1, x2);
    }
    x1 = 0;
    x2 = 0;
    nroots = SolveEquation(0, 0, 3, &x1, &x2);
    if (!(nroots == 0 && x1 == 0 && x2 == 0))
    {
        printf("5 failled: x1 = %lf, x2 = %lf (should be x1 = nope, x2 = nope)",x1, x2);
    }
    x1 = 0;
    x2 = 0;
    nroots = SolveEquation(5, 1, 1, &x1, &x2);
    if (!(nroots == 0 && x1 == 0 && x2 == 0))
    {
        printf("6 failled: x1 = %lf, x2 = %lf (should be x1 = nope, x2 = nope)",x1, x2);
    }
    return 0;
}
