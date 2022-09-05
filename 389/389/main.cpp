#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count = vector<int>(26, 0);
        for (char c : s)
        {
            count[c - 'a'] += 1;
        }

        for (char c : t)
        {
            count[c - 'a'] -= 1;
            if (count[c - 'a'] < 0)
            {
                return c;
            }
        }
        return ' ';
    }
};

int main()
{
    Solution solution;
    string s = "abcd";
    string t = "eabdc";
    cout << solution.findTheDifference(s, t) << endl;
}