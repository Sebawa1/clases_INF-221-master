/**
 * @file  beer-select.c
 * @brief Find out which bottles to drink
 */

#include <stdbool.h>
#include <stdio.h>

const int N = 32;
int n;
double v[N];
bool wins[N], drink[N];

double beer(int);
void select(int);

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", &v[i]);
    printf("M = %f\n", beer(n));
    select(n);
    for(int i = 0; i < n; i++)
        if(drink[i])
            printf("%d (%lf)\n", i, v[i]);
}

double beer(int n)
{
    double mb[n > 1 ? n + 1 : 2];

    mb[0] = 0.0;
    mb[1] = v[0];
    wins[0] = true;

    for(int i = 2; i <= n; i++)
        if(mb[i - 1] > mb[i - 2] + v[i - 1]) {
            mb[i] = mb[i - 1];
            wins[i - 1] = false;
        }
        else {
            mb[i] = mb[i - 2] + v[i - 1];
            wins[i - 1] = true;
        }
    return mb[n];
}

void select(int n)
{
    if(n <= 0)
        return;
    if(wins[n - 1]) {
        drink[n - 1] = true;
        select(n - 2);
    }
    else
        select(n - 1);
}
