#include <stdio.h>
char reverse (char s[])
{
    int i = 0;
    long l = 0;
    char x = 0;
    for (i = 0; s[i] != '\n'; ++i)
    {
        ++l;
    }
    i = 0;
    while (i < l - 1)
    {
       x = s[i];
       s[i] = s[l];
       s[l] = x;
       ++i;
       --l;
    }
    return s;

int main()
{
    char s[100] = "123456";
    s = reverse(s);
    printf("%s", s);
    return 0;
}

