#include<iostream>
#include<algorithm>
using namespace std;
void sortArray(int arr[], int size) {
    if (size == 0 || size == 1) {
        return ;
    }
    for (int i = 0; i < size - 1; i++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
    return sortArray(arr, size - 1);
}