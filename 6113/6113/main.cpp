#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class SmallestInfiniteSet {
private:
    int now = 0;
    priority_queue<int, vector<int>, greater<int>> nowSet;
    vector<int> has;
public:
    SmallestInfiniteSet() {
        now = 0;
        has = vector<int>(1001, false);
    }

    int popSmallest() {
        if (nowSet.empty())
        {
            now += 1;
            return now;
        }
        else
        {
            int next = nowSet.top();
            nowSet.pop();
            has[next] = false;
            return next;
        }
    }

    void addBack(int num) {
        if (num <= now && !has[num])
        {
            nowSet.push(num);
            has[num] = true;
        }
    }
};