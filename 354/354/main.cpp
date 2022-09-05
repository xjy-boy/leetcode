#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty())
        {
            return 0;
        }

        //第一维度升序
        //第二维度降序
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& e1, const vector<int>& e2)
        {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        
        
        vector<int> dp = vector<int>();
        dp.emplace_back(envelopes[0][1]);

        for (int i = 1; i < envelopes.size(); i++)
        {
            if (envelopes[i][1] > dp.back())
            {
                dp.emplace_back(envelopes[i][1]);
            }
            else
            {
                auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }

        return dp.size();
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = {
        {2,100},
        {3,200},
        {4,300},
        {5,500},
        {5,400},
        {5,250},
        {6,370},
        {6,360},
        {7,380}
    };
    cout << s.maxEnvelopes(nums) << endl;
}