#include <stdio.h>

long long int fib[10005] = {};

long long int fibonacci(int i)
{
    if (i < 2)
    {
        return i;
    }

    if (fib[i] > 0)
    {
        return fib[i];
    }

    fib[i] = fibonacci(i - 1) + fibonacci(i - 2);

    return fib[i];
}

int main()
{
    for (int i = 0; i < 50; i++)
    {
        printf("%lld\n", fibonacci(i));
    }

    return 0;
}