#include<iostream>

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
private:
	int ans = 0;

public:
	int minDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		ans = INT_MAX;
		inOrder(root, 1);
		return ans;
		
	}

	void inOrder(TreeNode* root,int high)
	{
		if (high >= ans)
		{
			return;
		}
		else if (!root->left && !root->right)
		{
			ans = high;
		}
		else
		{
			if (root->left)
			{
				inOrder(root->left, high + 1);
			}

			if (root->right)
			{
				inOrder(root->right, high + 1);
			}
		}
	}
};