#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int ansR = m;
        int ansC = n;
        for (vector<int>& op : ops)
        {
            ansR = min(ansR, op[0]);
            ansC = min(ansC, op[1]);
        }
        return ansR * ansC;
    }
};