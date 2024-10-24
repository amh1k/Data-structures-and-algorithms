#include <iostream>
using namespace std;
int peakElement(int arr[], int n)
{

    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];
    int start = 1, end = n - 2;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] > arr[mid - 1])
        {
            start = mid + 1;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
