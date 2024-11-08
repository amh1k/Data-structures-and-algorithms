//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void heapify(vector<int>& arr, int i, int n) {
    int largest = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    if (leftIndex < n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    if (rightIndex < n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for (int i = N/2 - 1; i>= 0; i--) {
            heapify(arr, i, N);
        }
    
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends