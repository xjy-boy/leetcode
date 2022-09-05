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
public:
	int sumRootToLeaf(TreeNode* root) {
		return sumRootToLeaf(root, 0);
	}

	int sumRootToLeaf(TreeNode* root,int preSum) {
		if (!root)
		{
			return 0;
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			return preSum * 2 + root->val;
		}
		else
		{
			preSum = preSum * 2 + root->val;
			return sumRootToLeaf(root->left, preSum) + sumRootToLeaf(root->right, preSum);
		}
	}
};

int main()
{
	TreeNode node1(1);
	TreeNode node2(0);
	TreeNode node3(1);
	TreeNode node4(0);
	TreeNode node5(1);
	TreeNode node6(0);
	TreeNode node7(1);

	node1.left = &node2;
	node1.right = &node3;

	node2.left = &node4;
	node2.right = &node5;

	node3.left = &node6;
	//node3.right = &node7;

	Solution s;
	cout << s.sumRootToLeaf(&node1) << endl;
}