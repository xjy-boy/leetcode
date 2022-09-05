#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

struct NumPair {
    int num1;
    int num2;
    int sum;
    NumPair(int _num1, int _num2,int _sum)
    {
        num1 = _num1;
        num2 = _num2;
        sum = _sum;
    }
    bool operator < (const NumPair n)const
    {
        return sum < n.sum;
    }

    bool operator > (const NumPair n)const
    {
        return sum > n.sum;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        vector<vector<int>> result;
        priority_queue<NumPair, vector<NumPair>, greater<NumPair>> smallHeap;
        unordered_set<int> flagSet;
        smallHeap.push(NumPair(0, 0, nums1[0] + nums2[0]));
        flagSet.emplace(0);
        while (result.size() < k && !smallHeap.empty())
        {
            NumPair n = smallHeap.top();
            smallHeap.pop();
            result.push_back({ nums1[n.num1],nums2[n.num2] });
            if (n.num1 + 1 < length1 && !flagSet.count((n.num1 + 1) * length2 + n.num2))
            {
                NumPair n1 = NumPair(n.num1 + 1, n.num2, nums1[n.num1 + 1] + nums2[n.num2]);
                smallHeap.push(n1);
                flagSet.emplace(n1.num1 * length2 + n1.num2);
            }
            if (n.num2 + 1 < length2 && !flagSet.count(n.num1 * length2 + n.num2 + 1))
            {
                NumPair n2 = NumPair(n.num1, n.num2 + 1, nums1[n.num1] + nums2[n.num2 + 1]);
                smallHeap.push(n2);
                flagSet.emplace(n2.num1 * length2 + n2.num2);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { 3 };
    int k = 3;
    Solution s;
    s.kSmallestPairs(nums1, nums2, k);
}