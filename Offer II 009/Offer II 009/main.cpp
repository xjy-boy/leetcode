#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int left = 0;
        int right = 0;
        int result = 0;
        while (right < nums.size())
        {
            //�����Ҷ˻���
            while (right < nums.size())
            {
                product *= nums[right];
                if (product >= k)
                {
                    break;
                }
                else
                {
                    result += right - left + 1;
                    right += 1;
                }
            }
            //�Ҷ˻�������δ��ͷ
            if (right < nums.size())
            {
                //������˻���
                while (left < right && product >= k)
                {
                    product /= nums[left];
                    left += 1;
                }
                //������˻���������λ��ʱ����⵱ǰ�Ƿ����
                if (product >= k)
                {
                    //������,���ô���
                    left += 1;
                    right += 1;
                    product = 1;
                }
                else
                {
                    //����Ҫ��
                    result += right - left + 1;
                    right += 1;
                }

            }
        }
        return result;
    }
};


int main()
{
    vector<int> nums = { 10,5,2,6};
    Solution solution = Solution();
    int k = 0;
    cout << solution.numSubarrayProductLessThanK(nums, k) << endl;
}