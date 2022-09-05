#include<iostream>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans = s.substr(n);
        return ans + s.substr(0, n);
    }
};

int main()
{
    Solution s;
    cout << s.reverseLeftWords("abcdefg", 2) << endl;
}