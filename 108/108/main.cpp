#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums,int start,int end) {
        if (start == end)
        {
            return new TreeNode(nums[start]);
        }
        else if (end == start + 1)
        {
            TreeNode* p1 = new TreeNode(nums[start]);
            TreeNode* p2 = new TreeNode(nums[end]);
            p1->right = p2;
            return p1;
        }
        else
        {
            int mid = (start + end) / 2;
            TreeNode* p = new TreeNode(nums[mid]);
            p->left = sortedArrayToBST(nums, start, mid - 1);
            p->right = sortedArrayToBST(nums, mid+1, end);
            return p;
        }
    }
};