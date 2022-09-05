#include<iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int nums[26] = { 0 };
        if (s.size() != t.size())
        {
            return false;
        }
        bool sameFlag = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
            {
                sameFlag = false;
            }
            nums[s[i] - 'a'] += 1;
            nums[t[i] - 'a'] -= 1;
        }
        for (int num : nums)
        {
            if (num != 0)
            {
                return false;
            }
        }
        return !sameFlag;
    }
};

int main()
{
    Solution solution = Solution();
    string s = "rat";
    string t = "rat";
    cout << solution.isAnagram(s, t) << endl;
}