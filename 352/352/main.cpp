#include<iostream>
#include<vector>

using namespace std;


class SummaryRanges {
private:
    vector<int> fx;
    int maxNum = -1;
    int find(int x)
    {
        int px = x;
        while (fx[px] != px)
        {
            px = fx[px];
        }
        fx[x] = px;
        return px;
    }

    //true代表发生合并
    //保证x>y
    bool group(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
        {
            return false;
        }
        else
        {
            fx[py] = px;
            return true;
        }
    }
public:
    SummaryRanges() {
        fx = vector<int>(10001, -1);
    }

    void addNum(int val) {
        if (fx[val] == -1)
        {
            fx[val] = val;
            if (val != 0 && fx[val - 1] != -1)
            {
                group(val, val - 1);
            }
            if (fx[val + 1] != -1)
            {
                group(val + 1, val);
            }
        }
        maxNum = max(maxNum, val);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<int> now = { 0,0 };
        while (now[0] <= maxNum)
        {
            if (fx[now[0]] == -1)
            {
                now[0] += 1;
            }
            else
            {
                now[1] = find(now[0]);
                ans.emplace_back(now);
                now[0] = now[1] + 1;
            }
        }
        return ans;
    }
};

int main()
{
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);      // arr = [1]
    summaryRanges.getIntervals(); // 返回 [[1, 1]]
    summaryRanges.addNum(3);      // arr = [1, 3]
    summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
    summaryRanges.addNum(7);      // arr = [1, 3, 7]
    summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
    summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
    summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
    summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
    summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
}