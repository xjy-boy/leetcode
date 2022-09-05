#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Definition for a Node.
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if (!root)
        {
            return ans;
        }
        queue<Node*> searchQueue;
        searchQueue.push(root);
        while (!searchQueue.empty())
        {
            ans.push_back(vector<int>());
            int size = searchQueue.size();
            for (int i = 0; i < size; i++)
            {
                Node* node = searchQueue.front();
                searchQueue.pop();
                for (Node* next : node->children)
                {
                    searchQueue.push(next);
                }
                ans.back().push_back(node->val);
            }
        }
        return ans;
    }
};