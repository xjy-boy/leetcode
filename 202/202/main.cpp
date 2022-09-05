#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int pow[10] = {
            0,1,4,9,16,25,36,49,64,81
        };
        int next = n;
        while (!s.count(next))
        {
            s.insert(next);
            int t = 0;
            while (next != 0)
            {
                t += pow[next % 10];
                next = next / 10;
            }
            next = t;
        }
        return next == 1;
    }
};