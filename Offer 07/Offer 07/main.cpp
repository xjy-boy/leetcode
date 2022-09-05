#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	unordered_map<int, int> index;
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty())
		{
			return nullptr;
		}
		index.clear();
		for(int i = 0; i < inorder.size(); i++)
		{
			index[inorder[i]] = i;
		}
		TreeNode* root = new TreeNode(preorder[0]);
		TreeNode* p = root;
		stack<TreeNode*> nodeStack;
		for (int i = 1; i < preorder.size(); i++)
		{
			if (index[preorder[i]] < index[p->val])
			{
				p->left = new TreeNode(preorder[i]);
				nodeStack.push(p);
				p = p->left;
			}
			else
			{
				while (!nodeStack.empty() && index[nodeStack.top()->val] < index[preorder[i]])
				{
					p = nodeStack.top();
					nodeStack.pop();
				}
				p->right = new TreeNode(preorder[i]);
				p = p->right;
			}
		}
		return root;
	}
};

int main()
{
	Solution s;
	vector<int> pre = { 3,9,20,15,7 };
	vector<int> in = { 9, 3, 15, 20, 7 };
	s.buildTree(pre, in);
}