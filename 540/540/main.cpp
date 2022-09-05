#include<vector>
#include<cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (right != left) {
            mid = (left + right) / 2;
            mid -= mid & 1;
            if (nums[mid + 1] == nums[mid]) {
                left = mid + 2;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};


int main() {
    Solution solution = Solution();
    vector<int> num1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    vector<int> num2 = { 3,3,7,7,10,11,11 };
    vector<int> num3 = { 3,3,5,7,7,11,11 };
    vector<int> num4 = { 1, 1, 3, 3, 4, 4, 8, 8 ,10 };
    cout << solution.singleNonDuplicate(num1) << endl;
    cout << solution.singleNonDuplicate(num2) << endl;
    cout << solution.singleNonDuplicate(num3) << endl;
    cout << solution.singleNonDuplicate(num4) << endl;
}