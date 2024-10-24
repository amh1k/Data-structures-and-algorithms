#include<iostream>
using namespace std;
int peakIndexArr(int arr[], int size) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s)/ 2;
    while (s < e) {
        if(arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        }else {
            e = mid;
        }
        mid = s+(e -s) / 2;
    }
    return s;



}