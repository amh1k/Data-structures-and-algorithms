#include <iostream>
using namespace std;
int lowerBound(int arr[], int n, int target)
{
    int ans = n;
    int start = 0, end = n - 1, mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] >= target)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int lowerBound(int arr[], int n, int target, int start, int end, int &ans)
{
    if (start > end)
    {
        return ans;
    }
    int mid = start + ((end - start) / 2);
    if (arr[mid] >= target)
    {
        ans = mid;
        lowerBound(arr, n, target, start, mid - 1, ans);
    }
    else
    {
        lowerBound(arr, n, target, mid + 1, end, ans);
    }
}