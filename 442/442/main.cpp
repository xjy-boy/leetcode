#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int index = 0;
        while (index < nums.size())
        {
            if (nums[index] < 0)
            {
                index += 1;
            }
            else if (nums[index] == index + 1)
            {
                index += 1;
            }
            //��nums[index]�ŵ�Ӧ�÷ŵ�λ��
                //����Ѿ�����
            else if(nums[index] == nums[nums[index] - 1])
            {
                ans.emplace_back(nums[index]);
                nums[index] = -1;
            }
            //����nums[index] ��nums[nums[index]-1]
            else
            {
                int t = nums[nums[index] - 1];
                nums[nums[index] - 1] = nums[index];
                nums[index] = t;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {
        1,1,2
    };
    Solution s;
    s.findDuplicates(nums);
}