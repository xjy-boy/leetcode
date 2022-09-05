#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        if (time == 0)
        {
            for (int i = 0; i < security.size(); i++)
            {
                ans.emplace_back(i);
            }
            return ans;
        }
        int i = 0;
        while (i + 2 * time < security.size())
        {
            int index = i;
            bool flag = true;
            for (i; i < index + time; i++)
            {
                if (security[i + 1] > security[i])
                {
                    i += 1;
                    flag = false;
                    break;
                }
            }
            int midIndex = i;
            while (flag && midIndex < security.size() - time)
            {
                for (i; i < midIndex + time; i++)
                {
                    if (security[i + 1] < security[i])
                    {
                        flag = false;
                        break;
                    }
                }
                //满足条件
                if (flag)
                {
                    ans.emplace_back(midIndex);
                    //检测滑动条件
                    if (security[midIndex] == security[midIndex + 1])
                    {
                        midIndex += 1;
                    }
                    else
                    {
                        flag = false;
                        i = midIndex + 1;
                    }
                }
                else if (i == midIndex&&security[midIndex + 1] <= security[midIndex])
                {
                    flag = true;
                    midIndex += 1;
                    i += 1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> security = { 2,1,1,1 };
    int time = 1;
    s.goodDaysToRobBank(security, time);
}