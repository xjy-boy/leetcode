#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candleNum;
        vector<int> ans;
        int num = 0;
        for (char c : s)
        {
            if (c == '|')
            {
                num += 1;
            }
            candleNum.emplace_back(num);
        }

        for (vector<int>query : queries)
        {
            int leftIndex = query[0];
            int rightIndex = query[1];
            if (candleNum[leftIndex] == candleNum[rightIndex])
            {
                ans.emplace_back(0);
                continue;
            }
            if (s[leftIndex] != '|')
            {
                leftIndex = lower_bound(candleNum.begin() + leftIndex, candleNum.begin() + rightIndex, candleNum[leftIndex] + 1) - candleNum.begin();
            }
            if (s[rightIndex] != '|')
            {
                rightIndex = lower_bound(candleNum.begin() + leftIndex, candleNum.begin() + rightIndex, candleNum[rightIndex]) - candleNum.begin();
            }
            ans.emplace_back(max(0, rightIndex - leftIndex - candleNum[rightIndex]+ candleNum[leftIndex]));
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {{1, 17}, {3, 6}, {2, 6}, {5, 11}, {15, 16}};
    solution.platesBetweenCandles(s, queries);
}