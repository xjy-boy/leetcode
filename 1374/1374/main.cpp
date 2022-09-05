#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string ans;
        if (n % 2 != 0)
        {
            ans = string(n, 'a');
        }
        else
        {
            if (n != 1)
            {
                ans = string(n - 1, 'a');
            }
            ans += 'b';
        }
        return ans;
    }
};