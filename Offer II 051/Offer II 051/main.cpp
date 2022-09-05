#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

class Solution {
private:
    int result;
public:
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        dfs(root);
        return result;
    }

    int dfs(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        int r1 = dfs(root->left);
        int r2 = dfs(root->right);

        int returnValue = max(r1 + root->val, r2 + root->val);
        returnValue = max(returnValue,root->val);
        result = max(result, returnValue);
        result = max(result, r1 + root->val + r2);
        return returnValue;
    }
};

int main()
{
    Solution solution;
    Codec c;
    TreeNode* root = c.deserialize("-10,9,20,null,null,15,7");
    cout << solution.maxPathSum(root) << endl;
}
