#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> rows = {
        2,3,3,2,1,
        2,2,2,1,2,
        2,2,3,3,1,
        1,1,1,2,1,
        1,3,1,3,1,3
    };
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        bool insert = true;
        int row = -1;
        for (string s : words)
        {
            int row = -1;
            insert = true;
            for (char c : s)
            {
                if (c < 'a')
                {
                    if (row > 0 && row != rows[c + 32 - 'a'])
                    {
                        insert = false;
                        break;
                    }
                    row = rows[c + 32 - 'a'];
                }
                else
                {
                    if (row > 0 && row != rows[c - 'a'])
                    {
                        insert = false;
                        break;
                    }
                    row = rows[c - 'a'];
                }
            }
            if (insert)
            {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> input = { "Hello","Alaska","Dad","Peace" };
    s.findWords(input);
}