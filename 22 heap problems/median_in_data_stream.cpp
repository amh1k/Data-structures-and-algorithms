#include<bits/stdc++.h>
using namespace std;


class MedianFinder {
public:
    priority_queue<double> maxi;
    priority_queue<double, vector<double>, greater<double>> mini;
    double median;

    MedianFinder() {
        median = 0.0;
    }

    int signum(int a, int b) {
        if (a == b) return 0;
        return a > b ? 1 : -1;
    }

    void callMedian(double element, priority_queue<double>& maxi,
                    priority_queue<double, vector<double>, greater<double>>& mini) {
        switch (signum(maxi.size(), mini.size())) {
            case 0:
                if (element > median) {
                    mini.push(element);
                    median = mini.top();
                } else {
                    maxi.push(element);
                    median = maxi.top();
                }
                break;
            case 1:
                if (element > median) {
                    mini.push(element);
                } else {
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                }
                median = (maxi.top() + mini.top()) / 2.0;
                break;
            case -1:
                if (element > median) {
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                } else {
                    maxi.push(element);
                }
                median = (maxi.top() + mini.top()) / 2.0;
                break;
        }
    }

    void addNum(double num) {
        callMedian(num, maxi, mini);
    }

    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
