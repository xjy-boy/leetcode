#include<vector>

using namespace std;


class Solution {
private:
    int count[21] = { 0 };
    vector<int> result;
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (int num : nums)
        {
            count[num + 10] += 1;
        }
        backsearch(0);
        return ans;
    }

    void backsearch(int index)
    {
        if (index > 20)
        {
            ans.emplace_back(result);
            return;
        }
        
        backsearch(index + 1);
        int oldSize = result.size();
        for (int j = 0; j < count[index]; j++)
        {
            result.emplace_back(index - 10);
            backsearch(index + 1);
        }
        result.erase(result.begin() + oldSize, result.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 0 };
    s.subsetsWithDup(nums);
}