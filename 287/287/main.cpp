#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int num1 = nums[0];
        int num2 = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            num1 = num1 ^ nums[i];
            num2 = num2 ^ i;
        }
        return num1 ^ num2;
    }
};