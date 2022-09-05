#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size())
        {
            return result;
        }
        int mask1[26] = { 0 };
        int mask2[26] = { 0 };
        int i = 0;
        int length = s.size() - p.size();
        for (int j = 0; j < p.size(); j++)
        {
            mask1[s[j] - 'a'] += 1;
            mask2[p[j] - 'a'] += 1;
        }

        if (equal(mask1, mask2))
        {
            result.push_back(0);
        }

        for (int i = 1; i <= length; i++)
        {
            mask1[s[i - 1] - 'a'] -= 1;
            mask1[s[i + p.size() - 1] - 'a'] += 1;
            if (equal(mask1, mask2))
            {
                result.push_back(i);
            }
        }

        return result;
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
    string s = "abab";
    string p = "abedqewq";
    Solution solution = Solution();
    vector<int> result = solution.findAnagrams(s, p);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;
}