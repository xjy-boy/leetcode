#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {        
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (right == nums.size() - 1 && nums[right] == nums.size() - 1) {
            return nums.size();
        }
        else{
            return nums[right] - 1;
        }
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums1 = { 0};
    vector<int> nums2 = { 0,1,2,3,4,5,6,7,9 };
    vector<int> nums3 = { 0,1,3,4,5,6,7,8,9 };
    vector<int> nums4 = { 0,1,2,3,5,6,7,8,9 };
    cout << solution.missingNumber(nums1) << endl;
    //cout << solution.missingNumber(nums2) << endl;
    //cout << solution.missingNumber(nums3) << endl;
    //cout << solution.missingNumber(nums4) << endl;
}