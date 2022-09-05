#include<iostream>
#include<vector>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
        {
            return 0;
        }
        int ans = 0;
        int res = 0;
        for (Node*& child : root->children)
        {
            res = maxDepth(child);
            ans = max(ans, res);
        }
        return ans + 1;
    }
};