#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2)
{
    for (int i = 0; i < min(s1.size(), s2.size()); i++)
    {
        if (s1[i] < s2[i])
        {
            return true;
        }
        else if (s1[i] > s2[i])
        {
            return false;
        }
    }
    if (s1.size() == s2.size())
    {
        return false;
    }
    else if (s1.size() > s2.size())
    {
        return compare(s1.substr(s2.length()), s2);
    }
    else
    {
        return compare(s1, s2.substr(s1.length()));
    }
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> stringList;
        for (int num : nums)
        {
            stringList.push_back(to_string(num));
        }
        sort(stringList.begin(), stringList.end(), compare);
        string ans;
        for (string s : stringList)
        {
            ans += s;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 30,1,3,30,34,5,9 };
    cout << s.minNumber(nums) << endl;
}