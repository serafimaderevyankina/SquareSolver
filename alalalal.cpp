#include <stdio.h>
main ()
{
    int c;
    c = 0;
    while ((c = getchar()) != '\n')
    {
        if ((c == '\t') || (c == '\b'))
        {
            c = '\\';
        }
        putchar(c);
    }
    return 0;
}
