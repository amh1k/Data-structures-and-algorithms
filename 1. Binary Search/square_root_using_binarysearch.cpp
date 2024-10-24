#include<iostream>
using namespace std;
 long long int binarySearch(int n) {
    int s = 0, e = n;
    long long int mid = s + (e - s)/ 2, ans = -1;
    while (s <=e ) {
        int square = mid * mid;
        if (square == n) {
            return mid;
        }
        if (square < n) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
    
    
}
double morePrecison(int n, int precison, int tempsol) {
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precison; i++) {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor) {
            ans = j;
        }
    }
    return ans;
}
int main () {

}