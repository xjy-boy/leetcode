#include<iostream>
#include<vector>

using namespace std;

/*
* ִ����ʱ��0 ms, ������ C++ �ύ�л�����100.00%���û�
* �ڴ����ģ�6.8 MB, ������ C++ �ύ�л�����91.34%���û�
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1 << nums.size());
        //result[1].push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < (1 << i); j++)
            {
                int index = j + (1 << i);
                result[index].assign(result[j].begin(),result[j].end());
                result[index].push_back(nums[i]);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3 };
    s.subsets(nums);
}