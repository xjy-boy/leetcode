#include<iostream>
#include<queue>
#include<string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
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

        //���Ҹ��ڵ�
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
            while (end < data.size()&&data[end] != ',')
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

int main()
{
    Codec ser, deser;
    TreeNode* root = deser.deserialize("");
    cout << ser.serialize(root) << endl;
}