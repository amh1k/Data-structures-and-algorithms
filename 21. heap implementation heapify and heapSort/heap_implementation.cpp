#include<iostream>
using namespace std;
class Heap {
    int arr[100];
    int size;
    public:
    Heap() {
        arr[0] = -1;
        size = 0;
    }
    void insertIntoHeap(int val) {
        size = size + 1;
        arr[size] = val;
        int i = size;
        while (i > 1) {
            if (arr[i] > arr[i / 2]) {
                swap(arr[i], arr[i / 2]);
                i = i /2;
            }
            else {
                return;
            }

        }

    }
    void deleteFromHeap() {
        swap(arr[1], arr[size]);
        size--;
        int i = 1;
        while (i <= size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex] && leftIndex <= size && rightIndex <= size) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (arr[i] < arr[rightIndex] && arr[rightIndex] > arr[leftIndex] && leftIndex <= size && rightIndex <= size) {
                swap(arr[i], arr[leftIndex]);
                i = rightIndex;

            }
            else {
                return;
            }

        }
    }
    void heapify(int arr[], int i, int n) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (arr[largest] < arr[left] && arr[left] > arr[right] && (right <= size && left <= size )) {
            largest =  left;
        }
        if (arr[largest] < arr[right] && arr[right] > arr[left] && (right <= size && left <= size )) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, largest, n);
        }
        
    }
    

};