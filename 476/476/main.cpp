#include<iostream>

using namespace std;


class Solution {
public:
    int findComplement(int num) {
        int t = 1;
        
        while (t <= num)
        {
            num = num ^ t;
            if (t == (1 << 31))
            {
                break;
            }
            t = t << 1;
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout << s.findComplement(5) << endl;
}