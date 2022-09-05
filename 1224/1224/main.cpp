#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int numLittle = 0; //���ִ���С�ڵ�ǰ�����ִ��������ָ���
        int maxCount = 0; //��ǰ�����ִ���
        unordered_map<int, int> numCount;

        for (int i = 0; i < n; i++)
        {
            //ͳ�Ƹ������ֳ��ִ���
            if (!numCount[nums[i]])
            {
                numCount[nums[i]] = 1;
                if (maxCount > 0)
                {
                    numLittle += 1;
                }
            }
            else
            {
                numCount[nums[i]] += 1;
            }

            
            if (numCount[nums[i]] > maxCount)
            {
                numLittle = numCount.size() - 1;
                maxCount += 1;
            }
            else if (numCount[nums[i]] == maxCount)
            {
                numLittle -= 1;
            }

            //����ǰ�������ֳ��ִ�����ͬ
            if (numLittle == 0 && i != n-1)
            {
                ans = i + 2;
            }
            //����ǰֻ��һ�����ֽ�����һ�Σ�����������ͬ
            else if (numLittle == 1 && 
                maxCount * (numCount.size()-1) == i)
            {
                ans = i + 1;
            }
            //����ǰֻ��һ�����ֳ�����maxCount�Σ��������ֳ���maxCount-1��
            else if (numLittle == numCount.size() - 1
                && (maxCount-1) * numCount.size() == i)
            {
                ans = i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
    cout << s.maxEqualFreq(nums) << endl;
}