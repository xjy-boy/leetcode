#include<iostream>
#include<queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> front;
    priority_queue<int,vector<int>,greater<int>> back;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (front.size() == back.size())
        {
            if (front.empty() || num <= front.top())
            {
                front.push(num);
            }
            else
            {
                back.push(num);
            }
        }
        else if (front.size() > back.size())
        {
            if (num >= front.top())
            {
                back.push(num);
            }
            else
            {
                front.push(num);
                back.push(front.top());
                front.pop();
            }
        }
        else
        {
            if (num <= back.top())
            {
                front.push(num);
            }
            else
            {
                back.push(num);
                front.push(back.top());
                back.pop();
            }
        }
    }

    double findMedian() {
        if (front.size() == back.size())
        {
            return (double)(front.top() + back.top()) / 2;
        }
        else if (front.size() > back.size())
        {
            return front.top();
        }
        else
        {
            return back.top();
        }
    }
};
