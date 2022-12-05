static void partition(const int lo, const int hi, int *lt, int *gt)
{
    int i = lo;
    double p = a[lo];

    *lt = lo;
    *gt = hi - 1;

    while(i <= *gt) {
        if(p < a[i])
            swap(&a[*lt++], &a[i++]);
        else if(p > a[i])
            swap(&a[i], &a[*gt--]);
        else
            i++;
    }
}
