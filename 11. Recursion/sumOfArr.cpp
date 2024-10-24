#include<iostream>
using namespace std;
int sum(int arr[], int size) {
    if (size == 0) {
        return 0;
    }
    if (size == 1) {
        return arr[size - 1];
    }
    return arr[0] + sum(arr + 1, size -1);
}
int main() {
    int arr[4] = {1,2,3,4};
    int sumArr = sum(arr, 4);
    cout << sumArr;
}