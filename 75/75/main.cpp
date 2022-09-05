#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colorNum[3] = { 0 };
        for (int num : nums)
        {
            colorNum[num] += 1;
        }
        int index = colorNum[0];
        for (int i = 0; i < index; i++)
        {
            nums[i] = 0;
        }
        index += colorNum[1];
        for (int i = colorNum[0]; i < index ; i++)
        {
            nums[i] = 1;
        }

        index += colorNum[2];
        for (int i = colorNum[0] + colorNum[1]; i < index; i++)
        {
            nums[i] = 2;
        }
    }
};
