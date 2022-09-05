#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int total = 0;
        for (int i = 0; i < 32; i++) {
            total = 0;
            for (int number : nums) {
                total += (number >> i) & 1;
            }
            result = result | ((total % 3) << i);
        }
        return result;
    }
};


int main() {
    Solution solution = Solution();
    vector<int> nums = { 2, 2,INT_MIN,2};
    cout << solution.singleNumber(nums) << endl;
}