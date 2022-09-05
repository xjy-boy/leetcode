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
private:
    vector<int> ans;
public:
    vector<int> postorder(Node* root) {
        ans.clear();
        post(root);
        return ans;
    }

    void post(Node* root)
    {
        if (!root)
        {
            return;
        }
        for (Node* child : root->children)
        {
            post(child);
        }
        ans.emplace_back(root->val);
    }
};

int main()
{
    Node node1 = Node(1);
    Node node2 = Node(2);
    Node node3 = Node(3);
    Node node4 = Node(4);
    Node node5 = Node(5);
    Node node6 = Node(6);

    node1.children.emplace_back(&node3);
    node1.children.emplace_back(&node2);
    node1.children.emplace_back(&node4);

    node3.children.emplace_back(&node5);
    node3.children.emplace_back(&node6);
    Solution s;
    s.postorder(&node1);
}
