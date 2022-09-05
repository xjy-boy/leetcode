#include<vector>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<random>
using namespace std;

class Solution {
private:
    vector<int> pro;
    vector<vector<int>> _rects;
    int sum;
    default_random_engine e;
public:
    Solution(vector<vector<int>>& rects) {
        e.seed(time(0));
        sum = 0;
        for (vector<int> rect : rects)
        {
            _rects.emplace_back(rect);
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];
            sum += (x2 - x1 + 1) * (y2 - y1 + 1);
            pro.push_back(sum);
        }
    }

    vector<int> pick() {
        int ans = e() % sum;
        auto it = upper_bound(pro.begin(), pro.end(),ans);
        int index = it - pro.begin();
        int x = e() % (_rects[index][2] - _rects[index][0] + 1) + _rects[index][0];
        int y = e() % (_rects[index][3] - _rects[index][1] + 1) + _rects[index][1];
        return { x,y };
    }
};

int main()
{
    vector<vector<int>> input = {
        {46699834,31953404,46701601,31953969} ,{-54914524,-28342520,-54912559,-28341176},{-69147537,-2141243,-69146801,-2139702},{35829817,67469181,35830153,67470607},{-30475670,12214991,-30474928,12216447}
    };
    Solution s(input);

    while (true)
    {
        s.pick();
    }
}