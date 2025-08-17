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
       enum numbers {'A' = 10, 'B', 'C', 'D', 'F'};
        a = a + s[i]*g;
    }
    printf("%d", a);
    return 0;

}

