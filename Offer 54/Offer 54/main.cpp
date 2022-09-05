#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
private:
	int ans;
public:
	int kthLargest(TreeNode* root, int k) {
		ans = 0;
		inorder(root, k);
		return ans;
	}

	void inorder(TreeNode* root, int &k)
	{
		if (!root)
		{
			return;
		}
  		inorder(root->right, k);
		if (k == 1)
		{
			ans = root->val;
			k -= 1;
			return;
		}
		else if (k > 1)
		{
			k -= 1;
		}
		else
		{
			return;
		}
		inorder(root->left, k);
	}
};


int main()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	node5.right = &node6;
	node5.left = &node3;
	node3.right = &node4;
	node3.left = &node2;
	node2.left = &node1;
	Solution s;
	cout << s.kthLargest(&node5, 3) << endl;
}