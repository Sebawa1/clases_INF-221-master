
/** @file  item.h
 *  @brief Declarations for items
 */

struct item {
    long long whatever;
};

static inline int cmp(struct item *pa, struct item *pb)
{
    if(pa->whatever < pb->whatever)
        return -1;
    else if(pa->whatever > pb->whatever)
        return 1;
    else
        return 0;
}
