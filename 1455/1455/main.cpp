#include<iostream>

using namespace std;


class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 0;
        int i = 0;
        int ans = 0;
        while (index < sentence.size())
        {
            ans += 1;
            for (i = 0; i < searchWord.size(); i++)
            {
                if (index >= sentence.size() || 
                    sentence[index] != searchWord[i])
                {
                    break;
                }
                else
                {
                    index += 1;
                }
            }

            if (i == searchWord.size())
            {
                return ans;
            }
            while (index < sentence.size() && sentence[index] != ' ')
            {
                index += 1;
            }
            index += 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string s1 = "this problem is an easy problem";
    string s2 = "pro";
    cout << s.isPrefixOfWord(s1, s2) << endl;
}