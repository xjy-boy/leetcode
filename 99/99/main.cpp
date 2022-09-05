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
	TreeNode *pre;
	TreeNode* node1;
	TreeNode* node2;
public:
	void recoverTree(TreeNode* root) {
		node1 = NULL;
		node2 = NULL;
		pre = NULL;
		inOrder(root);
		int t = node1->val;
		node1->val = node2->val;
		node2->val = t;
		return;
	}

	bool inOrder(TreeNode* root) {
		if (!root) {
			return false;
		}
		if (inOrder(root->left)) {
			return true;
		}
		
		if(pre != NULL && root->val < pre->val)
		{
			if (node1 == NULL)
			{
				node1 = pre;
				node2 = root;
			}
			else
			{
				node2 = root;
				return true;
			}
		}
		pre = root;

		if (inOrder(root->right)) {
			return true;
		}
		return false;
	}
};

int main()
{

}