#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
private:
    Node* pre;
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
        {
            return NULL;
        }
        Node newHead(0);
        pre = &newHead;
        Node* p = pre;
        inorder(root);
        while (p->right)
        {
            p = p->right;
        }
        p -> right = newHead.right;
        newHead.right->left = p;
        return newHead.right;
    }

    void inorder(Node* root) {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        pre->right = root;
        root->left = pre;
        pre = root;
        inorder(root->right);
    }
};

int main()
{
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    node4.left = &node2;
    node4.right = &node5;
    node2.left = &node1;
    node2.right = &node3;
    Solution s;
    s.treeToDoublyList(&node4);

}