/**
 * @file maximum.c
 * @brief Find maximum
 */

double maximum(const double a[], const int n)
{
    double max;

    max = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}
