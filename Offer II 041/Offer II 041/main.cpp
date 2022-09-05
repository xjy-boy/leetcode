#include<iostream>
#include<queue>

using namespace std;

class MovingAverage {
private:
    int windowSize;
    int nowSum;
    queue<int> data;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        nowSum = 0;
    }

    double next(int val) {
        if (data.size() == windowSize)
        {
            nowSum -= data.front();
            data.pop();
        }
        nowSum += val;
        data.push(val);

        return (double)nowSum / data.size();
    }
};

int main()
{
    MovingAverage m = MovingAverage(3);
    cout << m.next(1) << endl;
    cout << m.next(10) << endl;
    cout << m.next(3) << endl;
    cout << m.next(5) << endl;
}