

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
    TreeNode* pruneTree(TreeNode* root) {
        if (has1(root))
        {
            return root;
        }
        else
        {
            return nullptr;
        }
    }

    bool has1(TreeNode* root) {
        if (!root)
        {
            return false;
        }
        else
        {
            bool ans1 = has1(root->left);
            bool ans2 = has1(root->right);
            bool ans3 = root->val == 1;
            if (!ans1)
            {
                root->left = nullptr;
            }

            if (!ans2)
            {
                root->right = nullptr;
            }
            return ans1 || ans2 || ans3;
        }
    }
};

int main()
{
    Solution s;
    TreeNode node1(1);
    TreeNode node2(0);
    TreeNode node3(0);
    TreeNode node4(1);
    node1.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    s.pruneTree(&node1);
}