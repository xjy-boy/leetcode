#include<iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n % 2;
        while (n != 0)
        {
            n = (n - last) / 2;
            int t = n % 2;
            if (last == t)
            {
                return false;
            }
            else
            {
                last = t;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.hasAlternatingBits(5) << endl;
}