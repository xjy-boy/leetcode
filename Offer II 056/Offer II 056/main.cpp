#include<iostream>
#include<queue>
#include<string>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            string temple = "";
            int size = nodeQueue.size();
            bool hasNode = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = nodeQueue.front();
                nodeQueue.pop();
                if (front != nullptr)
                {
                    hasNode = true;
                    nodeQueue.push(front->left);
                    nodeQueue.push(front->right);
                    temple += to_string(front->val) + ",";
                }
                else
                {
                    temple += "null,";
                }
            }
            if (hasNode)
            {
                result += temple;
            }
            else
            {
                break;
            }
        }
        result.erase(result.end() - 1);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        int end = 0;
        TreeNode* root = nullptr;

        //先找根节点
        if (data.empty())
        {
            return nullptr;
        }
        else
        {
            while (end < data.size() && data[end] != ',')
            {
                end += 1;
            }
            root = stringToNode(data.substr(start, end - start));
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (end < data.size())
        {
            TreeNode* p = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* left;
            TreeNode* right;
            end += 1;
            start = end;
            while (end < data.size() && data[end] != ',')
            {
                end += 1;
            }
            left = stringToNode(data.substr(start, end - start));
            end += 1;
            start = end;
            while (end < data.size() && data[end] != ',')
            {
                end += 1;
            }
            right = stringToNode(data.substr(start, end - start));
            p->left = left;
            p->right = right;
            if (left != nullptr)
            {
                nodeQueue.push(left);
            }
            if (right != nullptr)
            {
                nodeQueue.push(right);
            }
        }
        return root;
    }

    TreeNode* stringToNode(string s)
    {
        if (s == "null")
        {
            return nullptr;
        }
        else
        {
            int val = atoi(s.c_str());
            TreeNode* p = new TreeNode(val);
            return p;
        }
    }
};

class BSTIterator {
private:
    TreeNode* Root;
    stack<TreeNode*> nodeStack;
public:
    BSTIterator(TreeNode* root) {
        Root = root;
        while (root)
        {
            nodeStack.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* node = nodeStack.top();
        int result = node->val;
        nodeStack.pop();
        node = node->right;
        while (node)
        {
            nodeStack.push(node);
            node = node->left;
        }
        return result;
    }

    bool hasNext() {
        return !nodeStack.empty();
    }
};

class LSTIterator {
private:
    TreeNode* Root;
    stack<TreeNode*> nodeStack;
public:
    LSTIterator(TreeNode* root) {
        Root = root;
        while (root)
        {
            nodeStack.push(root);
            root = root->right;
        }
    }

    int next() {
        TreeNode* node = nodeStack.top();
        int result = node->val;
        nodeStack.pop();
        node = node->left;
        while (node)
        {
            nodeStack.push(node);
            node = node->right;
        }
        return result;
    }

    bool hasNext() {
        return !nodeStack.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bigIterator = BSTIterator(root);
        LSTIterator smallIterator = LSTIterator(root);
        int left = bigIterator.next();
        int right = smallIterator.next();
        int sum = left + right;
        while (left != right)
        {
            while (left != right && sum < k)
            {
                left = bigIterator.next();
                sum = left + right;
            }
            while (left != right && sum > k)
            {
                right = smallIterator.next();
                sum = left + right;
            }
            if (left == right)
            {
                return false;
            }
            if (sum == k)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Codec c;
    TreeNode* root = c.deserialize("8,6,10,5,7,9,11");
    Solution solution;
    cout << solution.findTarget(root, 22) << endl;
}