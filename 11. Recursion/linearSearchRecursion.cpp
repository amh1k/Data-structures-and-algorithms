#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
    if (size == 0) {
        return false;
    }
    if (arr[0] == key) {
        return true;
    }
    else {
         return linearSearch(arr + 1, size -1, key);
    }
}
int main() {
    int arr[4] = {1,2,3,4};
    int key = 2;
    bool isFound = linearSearch(arr, 4, key);
    if (isFound) {
        cout << "Present";
    }
}