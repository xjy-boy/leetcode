#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct NumPair {
    int num;
    int count;
    NumPair(int _num, int _count)
    {
        num = _num;
        count = _count;
    }
    bool operator < (const NumPair n)const 
    {
        return count < n.count;
     }

    bool operator > (const NumPair n)const
    {
        return count > n.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        for (int num : nums)
        {
            if (numMap.count(num))
            {
                numMap[num] += 1;
            }
            else
            {
                numMap[num] = 1;
            }
        }
        vector<NumPair> sortVector;
        for (auto it : numMap)
        {
            sortVector.push_back(NumPair(it.first, it.second));
        }
        sort(sortVector.rbegin(), sortVector.rend());
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(sortVector[i].num);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 1,1,1,2,2,3 };
    int k = 2;
    Solution s;
    vector<int> result = s.topKFrequent(nums, k);
    for (int num : result)
    {
        cout << num << endl;
    }
}