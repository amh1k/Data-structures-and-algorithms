#include<iostream>
using namespace std;
bool binarySearch(int arr[], int s, int e, int k) {
    if (s > e) {
        return false;
    }
    int mid = s + (e -s) / 2;
    if(arr[mid] == k) {
        return true;
    }
    if (arr[mid] > k) {
        return binarySearch(arr, s, mid - 1, k);
    }
    else {
        return binarySearch(arr,mid + 1, e, k);

    }
}
int main() {
    int arr[4] = {1,2,3,4};
    if (binarySearch(arr, 0, 3, 4)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not dound" << endl;
    }
}