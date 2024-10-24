#include <iostream>
using namespace std;
int taylerSeries(int x, int n)
{
    if (n == 0)
        return 1;
    int val = pow(x, n) / fact(n);
    return val + taylerSeries(x, n - 1);
}