#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> indexMap;
        int ans = 0;
        int nowLength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (indexMap.count(s[i]) && indexMap[s[i]] >= i - nowLength)
            {
                ans = max(ans, nowLength);
                nowLength = i - indexMap[s[i]];
            }
            else
            {
                nowLength += 1;
            }
            indexMap[s[i]] = i;
        }
        return max(ans, nowLength);
    }
};

int main()
{
    Solution solution;
    string s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s) << endl;
}