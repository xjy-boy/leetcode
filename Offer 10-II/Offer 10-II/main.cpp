#include<iostream>

using namespace std;
class Solution {
public:
    int numWays(int n) {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            int n1 = 1;
            int n2 = 1;
            for (int i = 2; i < n; i++)
            {
                int t = (n1 + n2) % 1000000007;
                n1 = n2;
                n2 = t;
            }
            return n2;
        }
    }
};