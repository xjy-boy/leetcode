#include<iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0)
        {
            return 0;
        }
        else
        {
            int n1 = 0;
            int n2 = 1;
            for (int i = 1; i < n; i++)
            {
                int t =( n1 + n2) % 1000000007;
                n1 = n2;
                n2 = t;
            }
            return n2;
        }
    }
};

int main()
{

}