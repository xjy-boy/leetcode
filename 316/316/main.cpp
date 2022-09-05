#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> nums = vector<int>(26, 0);
        for (char c : s)
        {
            nums[c - 'a'] += 1;
        }
        string ans;
        vector<bool> visit = vector<bool>(26, false);
        for (char c : s)
        {
            if (!visit[c - 'a'])
            {
                while (!ans.empty() && ans.back() > c && nums[ans.back() - 'a'] != 0)
                {
                    visit[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                visit[c - 'a'] = true;
                ans += c;
            }
            nums[c - 'a'] -= 1;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "cbacdcbc";
    cout << solution.removeDuplicateLetters(s) << endl;
}