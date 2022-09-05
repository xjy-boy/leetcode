#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* makeTree(vector<int> data) {
    TreeNode* root = new TreeNode(data[0]);
    root->left = nullptr;
    root->right = nullptr;
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < data.size() && !q.empty()) {
        TreeNode* p = q.front();
        q.pop();
        if (data[i] != INT_MIN) {
            p->left = new TreeNode(data[i]);
            q.push(p->left);
        }
        else {
            p->left = nullptr;
        }
        i++;
        if (i < data.size() && data[i] != INT_MIN) {
            p->right = new TreeNode(data[i]);
            q.push(p->right);
        }
        else {
            p->right = nullptr;
        }
        i++;
    }
    return root;
}

void display(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* p = q.front();
        cout << p->val << endl;
        q.pop();
        if (p->left != nullptr) {
            q.push(p->left);
        }
        if (p->right != nullptr) {
            q.push(p->right);
        }
    }
}

void freeTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* p = q.front();
        q.pop();
        if (p->left != nullptr) {
            q.push(p->left);
        }
        if (p->right != nullptr) {
            q.push(p->right);
        }
        delete(p);
    }
}


class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        vector<int> parents;
        parents.push_back(root->val);
        return max(maxDiff(root->left, parents), maxDiff(root->right, parents));
    }

    int maxDiff(TreeNode* root, vector<int> parents) {
        if (root == nullptr) {
            return 0;
        }
        else if (root->left == nullptr && root->right == nullptr) {
            int result = 0;
            int temple = 0;
            for (int i = 0; i < parents.size(); i++) {
                temple = abs(root->val - parents[i]);
                if (temple > result) {
                    result = temple;
                }
            }
            return result;
        }
        else {
            int result = 0;
            int temple = 0;
            for (int i = 0; i < parents.size(); i++) {
                temple = abs(root->val - parents[i]);
                if (temple > result) {
                    result = temple;
                }
            }
            parents.push_back(root->val);
            return max(result,max(maxDiff(root->left, parents), maxDiff(root->right, parents)));
        }
    }
};

int main() {
    Solution solution = Solution();
    TreeNode* root = makeTree({ 8,3,10,1,6,INT_MIN,14,INT_MIN,INT_MIN,4,7,13 });
    cout << solution.maxAncestorDiff(root) << endl;
    freeTree(root);
}