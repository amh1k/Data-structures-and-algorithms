#include<iostream>
using namespace std;
int binarySearch(int arr[], int s, int e, int key) {
    int start = s, end = e;
    int mid = start + (end-start) / 2;
    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end-start) / 2;

    }
    return - 1;
}
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
int findPosition(int arr[], int n, int k) {
    int pivot = getPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1]) {

        //Binary search on second line
        return binarySearch(arr, pivot, n -1, k);

    }
    //Bs on first line
    else {
        binarySearch(arr, 0, pivot - 1, k);
    }
}