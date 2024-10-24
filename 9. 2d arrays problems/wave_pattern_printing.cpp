#include<iostream>
using namespace std;
void printPattern(int rows, int cols,int arr[][3]) {
    for (int i = 0; i < cols; i++) {
        if (i & 1) {
            for (int j = rows - 1; j >= 0; j--) {
                cout << arr[i][j];
            }

        }
        else {
            for (int j = 0; j <= rows; j++) {
                cout << arr[i][j];

            }
        }
    }
}