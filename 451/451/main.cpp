#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<string> count = vector<string>(62, "");
        for (char c : s)
        {
            int index = 0;
            if (c >= 'a' && c <= 'z')
            {
                index = c - 'a';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                index = 26 + c - 'A';
            }
            else
            {
                index = 52 + c - '0';
            }

            count[index] += c;
        }

        string ans = "";
        int nextLength = 0;
        int index = 0;
        while (true)
        {
            nextLength = 0;
            index = 0;
            for (int i = 0; i < 62; i++)
            {
                if (count[i].length() > nextLength)
                {
                    nextLength = count[i].length();
                    index = i;
                }
            }
            if (nextLength == 0)
            {
                break;
            }
            else
            {
                ans += count[index];
                count[index] = "";
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "Aabb";
    cout << solution.frequencySort(s) << endl;
}