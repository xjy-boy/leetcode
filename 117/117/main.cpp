#include<iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
};

class Solution {
public:
    void handle(Node*& last, Node*& p, Node*& nextStart) {
        if (last) {
            last->next = p;
        }
        if (!nextStart) {
            nextStart = p;
        }
        last = p;
    }

    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node* start = root;
        while (start) {
            Node* last = nullptr, * nextStart = nullptr;
            for (Node* p = start; p != nullptr; p = p->next) {
                if (p->left) {
                    handle(last, p->left, nextStart);
                }
                if (p->right) {
                    handle(last, p->right, nextStart);
                }
            }
            start = nextStart;
        }
        return root;
    }
};
