#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

int maxSubArraySum(vector<int> arr, int k) {
    int windowSum = 0;
    int maxSum = INT_MIN;

    // Calculate the initial window sum of the first 'k' elements
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    // Set the maxSum to the initial window sum
    maxSum = windowSum;

    // Slide the window, updating the sums and finding the max sum
    for (int i = k; i < arr.size(); i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }
    
    return maxSum;
}

int main() {
    vector<int> cardPoints = {11, 49, 100, 20, 86, 29, 72};
    int k = 4;
    cout << "Max subarray sum of length " << k << " is: " << maxSubArraySum(cardPoints, k) << endl;
    return 0;
}
