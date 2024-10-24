#include<iostream>
using namespace std;

int *swapped_arr(int *arr, int size) {
    int i;
    for (i =0; i < size; i+=2) {
        if (i + 1 <size) {
            swap(arr[i], arr[i + 1]);
        }
    }
}