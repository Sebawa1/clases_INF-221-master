#include <iostream>

void snapl(int n)
{
    if(n == 0 || n == 2)
        return;
    if(n == 1)
        std::cout << 42 << std::endl;
    else {
        snapl(n - 2);
        snapl(n - 3);
        snapl(n - 2);
        snapl(n - 3);
        snapl(n - 2);
    }
}
