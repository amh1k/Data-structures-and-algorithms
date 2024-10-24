#include<iostream>
using namespace std;
int findUnique(int *arr, int size) {
    int i,ans = 0;
    for (i =0; i < size; i++) {
        ans = ans ^ arr[i];
    }
}
int main () {

}