#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr;
    vector<int>a(5,1);// 5 elements are intialized with 1
    vector<int>copy(a);// Copied vector a into copy;
    cout << arr.capacity();
    arr.push_back(1);
    //Size shows how many elements are there in arr
    //Capacity shows the total space the vector has
    arr.push_back(2);
    cout << arr.capacity();
    //First element // arr.front();
    //Last element sarr.back();
    arr.pop_back();// Removes last element from vector
    arr.clear();
    map<int, string> m;
    m[1] = "Moiz";
    m[2] = "abc";
    for (auto i:m) {
        cout << i.first << endl;
    }
}
