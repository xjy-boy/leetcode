#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		vector<int> ans;
		ans.resize(1000);
		queue<TreeNode*> searchQueue;
		searchQueue.push(root);
		TreeNode* p;
		while (searchQueue.empty())
		{
			p = searchQueue.front();
			searchQueue.pop();
			if (!p)
			{
				continue;
			}
			ans.emplace_back(p->val);
			searchQueue.push(p->left);
			searchQueue.push(p->right);
		}

		return ans;
	}
};