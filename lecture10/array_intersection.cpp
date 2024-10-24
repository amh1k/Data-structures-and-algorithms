#include<iostream>
using namespace std;
void intersection(int *arr1, int *arr2, int n1, int n2) {
    int i,j;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] <<endl;
                arr2[j] == INT8_MIN;
            }
        }
    }

    //Better appraoch
    //Two pointer approach
    while (i < n1 & j < n2) {
        if (arr1[i] == arr2[j] ) {
            cout << arr1[i];
            i++;
            j++;
        }
        else if(arr1[i] > arr2[j]) {
            j++;
        }
        else {
            i++;
        }
    }
}