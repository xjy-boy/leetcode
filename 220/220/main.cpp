#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int getIndex(int num, long length)
    {
        return num / length;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> bucket;
        long bucketLength = (long)t + 1;
        int start = 0;
        int end = 0;

        while (end < nums.size())
        {
            if (end - start > k)
            {
                bucket.erase(bucket.find(nums[start]));
                start += 1;
            }

            int index = getIndex(nums[end], bucketLength);
            if (bucket.count(index))
            {
                return true;
            }
            else
            {
                if (bucket.count(index - 1))
                {
                    long c = (long)nums[end] - (long)bucket[index - 1];
                    if (c < 0)
                    {
                        c = -c;
                    }
                    if (c <= t)
                    {
                        return true;
                    }
                }

                if (bucket.count(index + 1))
                {
                    long c = (long)nums[end] - (long)bucket[index + 1];
                    if (c < 0)
                    {
                        c = -c;
                    }
                    if (c <= t)
                    {
                        return true;
                    }
                }
                bucket[index] = nums[end];
                nums[end] = index;
                end += 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2147483647,-1,2147483647};
    s.containsNearbyAlmostDuplicate(nums, 1, 2147483647);
}