#include<iostream>
int rand7();
using namespace std;

class Solution {
public:
    int rand10() {
        int ans = 7;
        while (ans == 7)
        {
            ans = rand7();
        }
        int next = 0;
        if (ans % 2 == 0)
        {
            next = 5;
        }
        ans = 7;
        while (ans > 5)
        {
            ans = rand7();
        }
        return next + ans;
    }
};