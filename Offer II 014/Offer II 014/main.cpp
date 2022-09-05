#include<iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
        {
            return false;
        }
        int mask1[26] = { 0 };
        int mask2[26] = { 0 };
        int i = 0;
        int length = s2.size() - s1.size();
        for (int j = 0; j < s1.size(); j++)
        {
            mask1[s1[j] - 'a'] += 1;
            mask2[s2[j] - 'a'] += 1;
        }

        if (equal(mask1, mask2))
        {
            return true;
        }

        for (int i = 1; i <= length; i++)
        {
            mask2[s2[i - 1] - 'a'] -= 1;
            mask2[s2[i + s1.size()-1] - 'a'] += 1;
            if (equal(mask1, mask2))
            {
                return true;
            }
        }

        return false;
    }

    bool equal(int a[], int b[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
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
    string s1 = "ab";
    string s2 = "a";
    cout << solution.checkInclusion(s1, s2) << endl;
}
