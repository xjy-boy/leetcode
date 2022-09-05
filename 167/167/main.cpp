#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                break;
            }
            else if (sum < target)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
        return { left + 1,right + 1 };
    }
};