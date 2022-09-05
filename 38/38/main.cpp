#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        {
            return "1";
        }
        vector<vector<int>> num(2);
        vector<vector<int>> count(2);
        num[0] = { 1 };
        count[0] = { 1 };
        for (int i = 1; i < n; i++)
        {
            int nowIndex = i % 2;
            int preIndex = 1 - nowIndex;
            num[nowIndex].clear();
            count[nowIndex].clear();

        }
    } 
};