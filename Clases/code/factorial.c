/* factorial.c */

/* -- Recursive version */

unsigned int factorial(unsigned int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

/* -- Iterative version */

unsigned int factorial(unsigned int n)
{
    unsigned int f = 1;

    for(unsigned int k = 1; k <= n; k++)
        f *= k;
    return f;
}
