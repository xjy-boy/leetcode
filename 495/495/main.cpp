#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int pre = -1;
        int next = 0;
        for (int time : timeSeries)
        {
            next = time + duration;
            if (time > pre)
            {
                ans += duration;
            }
            else
            {
                ans += next - pre;
            }
            pre = next;
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1,2 };
    cout << s.findPoisonedDuration(nums, 2) << endl;
}