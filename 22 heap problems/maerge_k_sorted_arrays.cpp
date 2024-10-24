//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Node {
    public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c) {
        this->data = d;
        this->row = r;
        this->col = c;
    }
};
class Compare {
    public:
    bool operator()(Node* a, Node*  b) {
        return a->data > b->data;    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*, vector<Node*>, Compare>pq;
        
        for (int i = 0; i < K; i++) {
           int el = arr[i][0];
           pq.push(new Node(el, i, 0));
        }
        vector<int>ans;
        while (!pq.empty()) {
            Node *temp = pq.top();
            pq.pop();
            ans.push_back(temp->data);
            if (temp-> col + 1 < K) {
                
              pq.push(new Node(arr[temp->row][temp->col + 1], temp->row, temp->col + 1));
              
            }
        }
        return ans;
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends