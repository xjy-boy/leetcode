#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int, int> index;
		for (int i = 0; i < inorder.size(); i++)
		{
			index[inorder[i]] = i;
		}
		TreeNode virtualRoot;
		TreeNode* pre = &virtualRoot;
		stack<TreeNode*> buildStack;

		for(int i = postorder.size() - 1; i >= 0 ; i--)
		{
			TreeNode* p = new TreeNode(postorder[i]);
			if (buildStack.empty()) 
			{
				pre->left = p;
				buildStack.push(p);
			}
			else
			{
				if (index[postorder[i]] > index[buildStack.top()->val])
				{
					buildStack.top()->right = p;
					buildStack.push(p);
				}
				else
				{
					while (!buildStack.empty() && index[postorder[i]] < index[buildStack.top()->val])
					{
						pre = buildStack.top();
						buildStack.pop();
					}
					pre->left = p;
					buildStack.push(p);
				}
			}
		}
		return virtualRoot.left;
	}
};

int main()
{
	Solution s;
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postOrder = { 9,15,7,20,3 };
	s.buildTree(inorder, postOrder);
}