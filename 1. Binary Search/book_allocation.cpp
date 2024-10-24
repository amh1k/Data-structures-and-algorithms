#include<iostream>
using namespace std;
bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1, pageSum = 0;
    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if (studentCount > n || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int allocateBooks(int arr[], int n, int m) {
    int s = 0, e = n - 1, mid = s +(e - s) / 2;
    int sum = 0, ans = -1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    while (s <= e) {
        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        } 
     int s = 0, e = n - 1, mid = s +(e - s) / 2;

    }
    return ans;

}