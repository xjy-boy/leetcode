#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int token[26] = {0};
        bool flag = true;
        for (int i = 0; i < order.size(); i++)
        {
            token[order[i] - 'a'] = i;
        }

        for (int i = 1; i < words.size(); i++)
        {
            //±È½Ïwords[i]Óëwords[i-1]
            flag = false;
            int length = min(words[i].size(), words[i - 1].size());
            for (int j = 0; j < length; j++)
            {
                if (token[words[i][j] - 'a'] < token[words[i - 1][j] - 'a'])
                {
                    return false;
                }

                if (token[words[i][j] - 'a'] > token[words[i - 1][j] - 'a'])
                {
                    flag = true;
                    break;
                }
            }
            if(!flag && words[i].size() < words[i - 1].size())
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution = Solution();
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";

    cout << solution.isAlienSorted(words, order) << endl;
}