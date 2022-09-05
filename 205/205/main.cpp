#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> charMap1;
        unordered_map<char, char> charMap2;

        for (int i = 0; i < s.length(); i++)
        {
            auto it1 = charMap1.find(s[i]);
            if (it1 != charMap1.end())
            {
                if (it1->second != t[i])
                {
                    return false;
                }
            }
            else
            {
                charMap1[s[i]] = t[i];
            }

            auto it2 = charMap2.find(t[i]);
            if (it2 != charMap2.end())
            {
                if (it2->second != s[i])
                {
                    return false;
                }
            }
            else
            {
                charMap2[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main()
{
    string s = "badc";
    string t = "baba";
    Solution solution;
    cout << solution.isIsomorphic(s, t) << endl;
}