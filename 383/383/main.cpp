#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> nums = vector<int>(26, 0);
        for (char c : magazine)
        {
            nums[c - 'a'] += 1;
        }

        for (char c : ransomNote)
        {
            nums[c - 'a'] -= 1;
            if (nums[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};