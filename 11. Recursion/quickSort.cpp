#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;

    // Count elements smaller than the pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at its correct position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    // Partition the array around the pivot
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot && i < pivotIndex) {
            i++;
        }
        while (arr[j] > pivot && j > pivotIndex) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }

    int pivotIndex = partition(arr, s, e);

    // Recursively sort the left and right subarrays
    quickSort(arr, s, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, e);
}

int main() {
    int arr[] = {9, 3, 4, 2, 7, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
