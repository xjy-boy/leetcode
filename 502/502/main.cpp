#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //每次只能选择 capital 小于等于 w 的资产
        //在可选择的资产中，需要选择利润最大的

        priority_queue<int> selectQueue;
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>,vector<pair<int, int>>,decltype(cmp)> candidateQueue(cmp);
        for (int i = 0; i < profits.size(); i++)
        {
            if (capital[i] <= w)
            {
                selectQueue.push(profits[i]);
            }
            else
            {
                candidateQueue.push({profits[i],capital[i]});
            }
        }
        for (int i = 0; i < k - 1; i++)
        {
            if (selectQueue.empty())
            {
                break;
            }
            w += selectQueue.top();
            selectQueue.pop();
            while (!candidateQueue.empty()
                && candidateQueue.top().second <= w)
            {
                selectQueue.push(candidateQueue.top().first);
                candidateQueue.pop();
            }
        }
        if (!selectQueue.empty())
        {
            w += selectQueue.top();
        }
        return w;
    }
};

int main()
{
    Solution s;
    vector<int> profits = { 1,2,3,4 };
    vector<int> capital = { 0,0,1,1 };
    cout << s.findMaximizedCapital(2, 0, profits, capital) << endl;
}