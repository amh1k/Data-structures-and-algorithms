#include<iostream>
using namespace std;
int findDuplicate(int *arr, int size) {
    int ans = 0,i;
    for (i = 0; i < size; i++) {
        ans = ans ^ arr[i];

    }
    for (i = 1; i < size; i++) {
        ans = ans ^ i;
    }
    return ans;
}
int main () {

}