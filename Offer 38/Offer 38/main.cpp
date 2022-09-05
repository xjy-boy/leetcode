#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        if (s.size() == 1)
        {
            return { s };
        }
        unordered_set<char> visited;
        vector<string> ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (visited.count(s[i]))
            {
                continue;
            }
            string t = s;
            t.erase(t.begin() + i, t.begin() + i + 1);
            vector<string> result = permutation(t);
            for (string r : result)
            {
                ans.emplace_back(s[i] + r);
            }
            visited.insert(s[i]);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "abc";
    solution.permutation(s);
}