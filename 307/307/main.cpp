#include<iostream>
#include<vector>

using namespace std;


class TreeArray {
private:
    vector<int> tree;

    int lowbit(int x)
    {
        return x & (-x);
    }
public:
    TreeArray(vector<int>& nums)
    {
        tree = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            add(i + 1, nums[i]);
        }
    }

    void add(int index,int val)
    {
        while (index < tree.size())
        {
            tree[index] += val;
            index += lowbit(index);
        }
    }

    int preSum(int index)
    {
        int sum = 0;
        while (index > 0)
        {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }
};

class NumArray {
private:
    TreeArray treeArray;
    vector<int> _nums;
public:
    NumArray(vector<int>& nums) :treeArray(nums){
        _nums = vector<int>(nums);
    }

    void update(int index, int val) {
        treeArray.add(index + 1, val - _nums[index]);
        _nums[index] = val;
    }

    int sumRange(int left, int right) {
        return treeArray.preSum(right + 1) - treeArray.preSum(left);
    }
};

int main()
{
    vector<int> nums = { 1,3,5 };
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
}