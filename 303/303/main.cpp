#include<iostream>
#include<vector>

using namespace std;


class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum.emplace_back(0);
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            preSum.emplace_back(sum);
        }
    }

    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};


int main()
{
    vector<int> nums = { -2,0,3,-5,2,-1 };
    NumArray s = NumArray(nums);

    cout << s.sumRange(0, 2) << endl;
    cout << s.sumRange(2, 5) << endl;
    cout << s.sumRange(0, 5) << endl;
}