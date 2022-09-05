#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    struct TokenNum
    {
        unsigned int nums[26] = { 0 };

        bool operator ==(const TokenNum &num1) const
        {
            for (int i = 0; i < 26; i++)
            {
                if (nums[i] != num1.nums[i])
                {
                    return false;
                }
            }
            return true;
        }
    };

    struct TokenHash 
    {
        size_t operator()(const TokenNum& t) const
        {
            unsigned int result = 0;
            for (unsigned int num : t.nums)
            {
                result = (result << 1) + num;
            }
            return result;
        }
    };

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<TokenNum,int,TokenHash> wordMap;
        vector<vector<string>> result;
        for (string s : strs)
        {
            TokenNum t = TokenNum();
            for (char c : s)
            {
                t.nums[c - 'a'] += 1;
            }
            if (!wordMap.count(t))
            {
                result.push_back(vector<string>());
                wordMap[t] = result.size() - 1;
                result[result.size() - 1].push_back(s);
            }
            else
            {
                result[wordMap[t]].push_back(s);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution = Solution();
    //vector<string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<string> input = { "" };
    solution.groupAnagrams(input);
}