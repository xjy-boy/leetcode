#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
private:
    vector<bool> visit;
    unordered_set<string> wordSet;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        visit = vector<bool>(s.size(), false);
        
        for (string word : wordDict)
        {
            wordSet.insert(word);
        }
        return wordBreak(s, 0);
    }

    bool wordBreak(string &s, int start) {       
        if (visit[start])
        {
            return false;
        }
        else if (wordSet.count(s.substr(start)))
        {
            return true;
        }
        for (int i = 1; i <= s.size() - start; i++)
        {
            if (wordSet.count(s.substr(start, i)))
            {
                if (wordBreak(s, start + i))
                {
                    return true;
                }
            }
        }
        visit[start] = true;
        return false;
    }
};

int main()
{
    Solution s;
    vector<string> wordDict = { "apple", "pen" };
    string word = "applepen";
    cout << s.wordBreak(word, wordDict) << endl;
}