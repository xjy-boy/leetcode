#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int t = 0;

        //�ظ���
        int num1 = 0;
        //ȱʧ��
        int num2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1)
            {
                //�ҵ����ظ�����
                if (nums[nums[i] - 1] == nums[i])
                {
                    num1 = nums[i];
                    num2 = i + 1;
                    break;
                }
                else
                {
                    t = nums[i];
                    nums[i] = nums[t - 1];
                    nums[t - 1] = t;
                }
            }
        }
        return {num1,num2};
    }
};

int main()
{
    Solution s;
    vector<int>  nums = { 8,7,3,5,3,6,1,4 };
    s.findErrorNums(nums);
}