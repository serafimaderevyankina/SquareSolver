#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char s[100];
    int i = 0;
    int a = 0;
    long g = 0;
    scanf("%s", s);
    int n = strlen(s[100]);
    printf("%d", i);
    for (i = 2; i < n + 1; i++)
    {
        g = pow(16, n - i - 2);
        if (s[i] == 'A')
        {
            s[i] = 10;
        }
        if (s[i] == 'B')
        {
            s[i] = 11;
        }
        if (s[i] == 'C')
        {
            s[i] = 12;
        }
        if (s[i] == 'D')
        {
            s[i] = 13;
        }
        if (s[i] == 'E')
        {
            s[i] = 14;
        }
        if (s[i] == 'F')
        {
            s[i] = 15;
        }
        a = a + s[i]*g;
    }
    printf("%d", a);
    return 0;

}
