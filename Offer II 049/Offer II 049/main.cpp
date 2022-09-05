#include<iostream>
#include<queue>
#include<string>
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
public:
    int sumNumbers(TreeNode* root) {
        vector<pair<int, int>> resultList = postOrder(root);
        int result = 0;
        for (pair<int, int> num : resultList)
        {
            result += num.first;
        }
        return result;
    }

    vector<pair<int,int>> postOrder(TreeNode* root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return { pair<int,int>(root->val,0) };
        }
        else 
        {
            vector<pair<int, int>> result1;
            vector<pair<int, int>> result2;
            if (root->left != nullptr)
            {
                result1 = postOrder(root->left);
            }
            if (root->right != nullptr)
            {
                result2 = postOrder(root->right);
            }
            result1.insert(result1.end(), result2.begin(), result2.end());
            for (int i = 0; i < result1.size(); i++)
            {
                result1[i].second += 1;
                result1[i].first += root->val * pow(10, result1[i].second);
            }
            
            return result1;
        }
    }
};

int main()
{
    Solution solution;
    Codec c;
    TreeNode* root = c.deserialize("4,9,0,5,1");
    cout << solution.sumNumbers(root) << endl;
}