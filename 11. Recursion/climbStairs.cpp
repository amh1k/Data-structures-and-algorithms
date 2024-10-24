#include<iostream>
using namespace std;
int countStairs(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    return countStairs(n - 1) * countStairs(n - 2);
}