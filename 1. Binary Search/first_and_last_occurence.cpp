#include<iostream>
using namespace std;
int firstOccur(int  arr[], int n,int key ) {
    int s = 0, e = n - 1, mid = s + (e -s)/2, ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = key;
            e = mid - 1;
        }
        else if (key > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}
int lastOccur(int  arr[], int n,int key ) {
    int s = 0, e = n - 1, mid = s + (e -s)/2, ans = -1;
    while (s <= e) {
        if (arr[mid] == key) {
            ans = key;
            s = mid + 1;
        }
        else if (key > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}