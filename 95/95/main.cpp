#include<iostream>
#include<vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<vector<TreeNode*>> dp = vector<vector<TreeNode*>>(n + 1);
		TreeNode *node1 = new TreeNode(1);
		dp[0].push_back(NULL);
		dp[1].push_back(node1);
		for (int i = 2; i <= n; i++)
		{
			//以j作为根节点
			for (int j = 1; j <= i; j++)
			{
				for (int m = 0; m < dp[j - 1].size(); m++)
				{
					for (int n = 0; n < dp[i - j].size(); n++)
					{
						TreeNode* root = new TreeNode(j);
						root->left = dp[j - 1][m];
						copyTree(root->right, dp[i - j][n],j);
						dp[i].push_back(root);
					}
				}
			}
		}
		return dp[n];
	}

	void copyTree(TreeNode* &root1, TreeNode* &root2, int val) {
		if (!root2)
		{
			return;
		}
		root1 = new TreeNode(root2->val + val);
		copyTree(root1->left, root2->left, val);
		copyTree(root1->right, root2->right, val);
	}
};

int main()
{
	Solution s;
	s.generateTrees(3);
}