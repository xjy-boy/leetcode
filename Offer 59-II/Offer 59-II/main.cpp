#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MaxQueue {
private:
    queue<int> data;
    deque<int> bigQueue;
public:
    MaxQueue() {

    }

    int max_value() {
        if (data.empty())
        {
            return -1;
        }
        else
        {
            return bigQueue.front();
        }
    }

    void push_back(int value) {
        data.push(value);
        while (!bigQueue.empty() && value > bigQueue.back())
        {
            bigQueue.pop_back();
        }
        bigQueue.push_back(value);
    }

    int pop_front() {
        if (data.empty())
        {
            return -1;
        }
        else
        {
            if (data.front() == bigQueue.front())
            {
                bigQueue.pop_front();
            }
            int ans = data.front();
            data.pop();
            return ans;
        }
    }
};

int main()
{

}