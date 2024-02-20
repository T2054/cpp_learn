#include <stdio.h>
#include <stdlib.h>

#define N 4
#define TARGET 24
#define EPSILON 1e-6

int isZero(double x)
{
    return x > -EPSILON && x < EPSILON;
}

int solve24(double a[], int n)
{
    if (n == 1)
    {
        if (isZero(a[0] - TARGET))
        {
            printf("((%.0f", a[0]);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    double b[N];
    int m, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0, m = 0; j < n; j++)
        {
            if (i != j)
            {
                b[m++] = a[j];
            }
        }
        if (solve24(b, n - 1))
        {
            printf(" + %.0f)", a[i]);
            return 1;
        }
        if (solve24(b, n - 1))
        {
            printf(" - %.0f)", a[i]);
            return 1;
        }
        if (solve24(b, n - 1))
        {
            printf(" * %.0f)", a[i]);
            return 1;
        }
        if (solve24(b, n - 1))
        {
            printf(" / %.0f)", a[i]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    double numbers[N];
    printf("请输入四个数字，以空格分隔：\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &numbers[i]);
    }
    printf("计算24点结果为：\n");
    if (solve24(numbers, N))
    {
        printf(" = %d\n", TARGET);
    }
    else
    {
        printf("无法得到24点\n");
    }
    return 0;
}
