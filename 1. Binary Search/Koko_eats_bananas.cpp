 #include<iostream>
 #include<algorithm>
 #include<vector>
 using namespace std;
 
 bool isPossible(vector<int> arr, int h, int mid) {
    vector <int> temp;
       for (int i = 0; i < arr.size(); i++) {
        temp.push_back(arr[i]);

       }
        int hourCount = 0, i = 0;
        while (i < arr.size()) {
            if (temp[i] < mid) {
                hourCount++;
                i++;
            }
            else {
                hourCount++;
                temp[i] = temp[i] - mid;

            }
            if (hourCount > h) {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int max = *max_element(piles.begin(), piles.end());

        
        int s = 1, e = max, mid = s + (e -s)/2;
        int ans = -1;
        while (s <= e) {
            if (isPossible(piles, h, mid)) {
                e = mid - 1;
                ans = mid;
            }
            else {
                s = mid + 1;
            }
            mid = s +((e -s)/ 2);
        }
        return ans;
        
    }
    int main () {
        vector <int> arr = {3,6,7,11};
        int k = minEatingSpeed(arr, 8);
        cout << "Value of k is " << k << endl;
    }