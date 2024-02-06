#include <stdio.h>

unsigned fac(unsigned n)
{
    unsigned f;
    if (n == 0)
        f = 1;
    else
        f = n * fac(n - 1);
    return f;
}

int f(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    else
        return (f(n - 1) + f(n - 2));
}
