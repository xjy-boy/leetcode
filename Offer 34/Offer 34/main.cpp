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
private:
	vector<vector<int>> ans;
public:
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		if (!root)
		{
			return {};
		}
		else
		{
			return path(root, target); 
		}
	}

	vector<vector<int>> path(TreeNode* root, int target) {
		if (!root->left && !root->right)
		{
			if (root->val == target)
			{
				return { {root->val} };
			}
			else
			{
				return {};
			}
		}

		int next = target - root->val;
		vector<vector<int>> result;
		if (root -> left)
		{
			result = path(root->left, next);
			for (int i = 0; i < result.size(); i++)
			{
				result[i].insert(result[i].begin(), root->val);
			}
		}

		if (root->right)
		{
			vector<vector<int>> temple = path(root->right, next);
			for (int i = 0; i < temple.size(); i++)
			{
				temple[i].insert(temple[i].begin(), root->val);
				result.emplace_back(temple[i]);
			}
		}

		return result;
	}
};


int main()
{

}