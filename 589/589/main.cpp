#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    vector<int> ans;
public:
    vector<int> preorder(Node* root) {
        ans.clear();
        preOrder(root);
        return ans;
    }

    void preOrder(Node *root)
    {
        if (!root)
        {
            return;
        }
        ans.emplace_back(root->val);
        for (Node* node : root->children)
        {
            preOrder(node);
        }
    }
};
