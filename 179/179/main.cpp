#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<vector<string>> bucket = vector<vector<string>>(10);
        for (int num : nums)
        {
            string s = to_string(num);
            bucket[s[0] - '0' ].emplace_back(s);
        }
        string ans;
        for (int i = 9; i > 0; i--)
        {
            ans += largestNumber(bucket[i], 1, i);
        }
        for (string s : bucket[0])
        {
            ans += s;
        }
        return ans;
    }

    string largestNumber(vector<string>& nums,int index,int pre) {
        if (nums.empty())
        {
            return "";
        }
        else if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<vector<string>> bucket = vector<vector<string>>(10);
        string ans;
        string mid;
        for (string num : nums)
        {
            if (num.size() <= index)
            {
                mid += num;
            }
            else
            {
                bucket[num[index] - '0'].emplace_back(num);
            }
        }

        for (int i = 9; i >= pre; i--)
        {
            ans += largestNumber(bucket[i], index + 1, i);
        }
        ans += mid;
        for (int i = pre - 1; i >= 0; i--)
        {
            ans += largestNumber(bucket[i], index + 1, i);
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 34323,3432 };
    cout << s.largestNumber(nums) << endl;
}