#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<string> ans;
    vector<vector<char>> symbol =
    {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','b'},
        {'w','x','y','z'},
    };
public:
    vector<string> letterCombinations(string digits) {
        ans = vector<string>();
        letterCombinations(digits, 0, "");
        return ans;
    }

    void letterCombinations(string digits,int index,string s) {
        if (index == digits.size())
        {
            ans.emplace_back(s);
            return;
        }
        int symbolIndex = digits[index] - '2';
        for (int i = 0; i < symbol[symbolIndex].size(); i++)
        {
            letterCombinations(digits, index + 1, s + symbol[symbolIndex][i]);
        }
    }
};