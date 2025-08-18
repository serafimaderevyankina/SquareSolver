#include <stdio.h>
#include <math.h>
float a, b, c;
char* solver(float a,float b,float c);
int main(void)
{
    float as, bs, cs;
    char s[2];
    printf("%f", as);
    scanf("%f", as);
    scanf("%f", bs);
    scanf("%f", cs);
    printf("%f, %f, %f\n", as, bs, cs);
    s = solver(as, bs, cs);
    printf("%s", s);
}
char* solver( a, b, c)
{
    float a, b, c;
    char s[2];
    float d, x, y = 0;
    int i = 0;
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
