#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] < target) {
                left += 1;
            }
            else if (numbers[left] + numbers[right] > target) {
                right -= 1;
            }
            else {
                break;
            }
        }
        return { left,right };
    }
};