#include<iostream>
using namespace std;
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if  (b == 1) {
        return a;
    int ans = power(a, b/2);
}