#include <stdio.h>
#include <math.h>
int main(void)
{
    float a, b, c;
    char s[];
    printf("%f", a);
    scanf("%f", a);
    scanf("%f", b);
    scanf("%f", c);
    printf("%f, %f, %f\n", a, b, c);
    s = solver(a, b, c)
    printf("%s", s)
}
char* solver(int a, b, c)
{
    int a, b, c;
    int a, b, c;
    char s[];
    d = x = y = 0;
    int i = 0
    d = b*b - 4.0f*(a*c);
    /*printf("%f\n", d);*/
    if (a == 0)
    {
        if (b == 0)
        {
            return "no sense";
        }
        else
        {
            x = (-c/b);
            s[0] = x;
            return s;
         }
    }
    else if ( a != 0 && d < 0)
    {
           return "no sense";
    }
    else if ( a != 0 && d > 0)
    {
        x = ((-b - sqrt(d))/2.0f)/a;
        y = ((-b + sqrt(d))/2.0f)/a;
        s[0] = x;
        s[1] = y;
        return s;
    }
    else if (a != 0 && d == 0)
    {
        x  = -b/ (2.0f*a);
        s[0] = x;
        return s;
    }
}
