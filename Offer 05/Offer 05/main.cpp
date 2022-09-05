#include<iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string result = "";
        for (char c:s)
        {
            if (c == ' ')
            {
                result += "%20";
            }
            else
            {
                result += c;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.replaceSpace("We are happy.") << endl;
}