#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k % 2 == 1)
        {
            return medianSlidingWindowOdd(nums, k);
        }
        else
        {
            return medianSlidingWindowEven(nums, k);
        }
    }

    //���������,kΪ������kΪż��
    //����
    vector<double> medianSlidingWindowOdd(vector<int>& nums, int k) {
        int mid = 0;
        priority_queue<int> left; //�����
        priority_queue<int,vector<int>,greater<int>> right; //С����
        //��ʼ��
        for (int i = 0; i < k; i++)
        {
            left.push(nums[i]);
        }
        for (int i = 0; i < k / 2; i++)
        {
            right.push(left.top());
            left.pop();
        }
        mid = left.top();
        left.pop();
        vector<double> ans;
        ans.emplace_back(mid);
        unordered_map<int, int> counts;
        int pre = 0;

        for (int i = k; i < nums.size(); i++)
        {
            pre = nums[i - k];
            if (pre == nums[i])
            {
                ans.emplace_back(ans.back());
                continue;
            }
            //Ҫɾ��������Ϊmid����Ҫ��mid���д���
            if (pre != mid)
            {
                //Ҫɾ��������left��
                if (pre < mid)
                {
                    //��mid����left�У�����ƽ��
                    left.push(mid);
                }
                else
                {
                    //��mid����right�У�����ƽ��
                    right.push(mid);
                }
                if (!counts.count(pre))
                {
                    counts[pre] = 1;
                }
                else
                {
                    counts[pre] += 1;
                }
            }
            //��ʱ���Ա�֤left��right��top����Ҫ��ɾ������
            if (nums[i] > left.top())
            {
                right.push(nums[i]);
                mid = right.top();
                right.pop();
                while (counts.count(right.top()))
                {
                    if (counts[right.top()] == 1)
                    {
                        counts.erase(right.top());
                    }
                    else
                    {
                        counts[right.top()] -= 1;
                    }
                    right.pop();
                }
            }
            else
            {
                left.push(nums[i]);
                mid = left.top();
                left.pop();
                while (counts.count(left.top()))
                {
                    if (counts[left.top()] == 1)
                    {
                        counts.erase(left.top());
                    }
                    else
                    {
                        counts[left.top()] -= 1;
                    }
                    left.pop();
                }
            }
            ans.emplace_back(mid);
        }
        return ans;
    }

    //���������,kΪ������kΪż��
    //ż��
    vector<double> medianSlidingWindowEven(vector<int>& nums, int k) {
        priority_queue<int> left; //�����
        priority_queue<int, vector<int>, greater<int>> right; //С����
        //��ʼ��
        for (int i = 0; i < k; i++)
        {
            left.push(nums[i]);
        }
        for (int i = 0; i < k / 2; i++)
        {
            right.push(left.top());
            left.pop();
        }
        vector<double> ans;
        unordered_map<int, int> counts;
        int pre = 0;
        double leftNum = left.top();
        double rightNum = right.top();
        ans.emplace_back(leftNum + (rightNum - leftNum) / 2);

        for (int i = k; i < nums.size(); i++)
        {
            pre = nums[i - k];
            if (pre == nums[i])
            {
                ans.emplace_back(ans.back());
                continue;
            }
            //Ҫɾ������Ϊ�����top
            if (left.top() == pre)
            {
                left.pop();
                //��right.top��nums[i]�еĽ�Сֵ����left�У�����ƽ��
                right.push(nums[i]);
                left.push(right.top());
                right.pop();
            }
            else if (right.top() == pre)
            {
                right.pop();
                //��left.top��nums[i]�еĽϴ�ֵ����right�У�����ƽ��
                left.push(nums[i]);
                right.push(left.top());
                left.pop();
            }
            else
            {
                //Ҫɾ��������left��
                if (pre < left.top())
                {
                    //��right.top��nums[i]�еĽ�Сֵ����left�У�����ƽ��
                    right.push(nums[i]);
                    left.push(right.top());
                    right.pop();
                }
                else
                {
                    //��left.top��nums[i]�еĽϴ�ֵ����right�У�����ƽ��
                    left.push(nums[i]);
                    right.push(left.top());
                    left.pop();
                    //left.pop֮��left.top�п���Ϊ��ɾ������
                }
                if (!counts.count(pre))
                {
                    counts[pre] = 1;
                }
                else
                {
                    counts[pre] += 1;
                }
            }
            //pop֮��top�п���Ϊ��ɾ������
            while (counts.count(left.top()))
            {
                if (counts[left.top()] == 1)
                {
                    counts.erase(left.top());
                }
                else
                {
                    counts[left.top()] -= 1;
                }
                left.pop();
            }
            while (counts.count(right.top()))
            {
                if (counts[right.top()] == 1)
                {
                    counts.erase(right.top());
                }
                else
                {
                    counts[right.top()] -= 1;
                }
                right.pop();
            }
            leftNum = left.top();
            rightNum = right.top();
            ans.emplace_back(leftNum + (rightNum - leftNum) / 2);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,4,2,3 };
    s.medianSlidingWindow(nums, 4);
}