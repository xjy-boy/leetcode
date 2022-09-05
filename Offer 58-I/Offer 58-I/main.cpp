#include<iostream>
#include<vector>


using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string result;
        int index = 0;
        while (index < s.size() && s[index] == ' ')
        {
            index += 1;
        }
        while (index < s.size())
        {
            // Ê¶±ð×Ö·û
            string temple;
            while (index < s.size() && s[index] != ' ')
            {
                temple += s[index];
                index += 1;
            }
            while (index < s.size() && s[index] == ' ')
            {
                index += 1;
            }
            if (temple == "")
            {
                break;
            }
            else if (result == "")
            {
                result = temple;
            }
            else
            {
                result = temple + " " +result;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << "|"<<s.reverseWords("  hello world!  ") <<"|"<< endl;
}