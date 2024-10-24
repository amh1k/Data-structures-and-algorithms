#include<iostream>
using namespace std;
int getPivot(int arr[], int size) {
    int s = 0, e = size-1, mid = s+(e-s)/2;
    while (s < e) {
        if (arr[mid] >= arr[0]) {

            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e -s) / 2;
    }
    return s;
}