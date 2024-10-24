#include <iostream>
using namespace std;

int getMax(int *arr, int n)
{
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

void countSort(int *arr, int n, int exp)
{
    int *countArr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        countArr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        countArr[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        countArr[i] += countArr[i - 1];
    }
    int *temp = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        temp[countArr[(arr[i] / exp) % 10] - 1] = arr[i];
        countArr[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
    delete[] countArr;
    delete[] temp;
}

void radixSort(int *arr, int n)
{
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
