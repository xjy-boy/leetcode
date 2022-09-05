#include<iostream>
#include<vector>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
        {
            return NULL;
        }
        Node* p = head;
        Node* p1;
        Node* result;
        while (p)
        {
            p1 = new Node(p->val);
            p1->next = p->next;
            p1->random = p->random;
            p->next = p1;
            p = p1->next;
        }
        result = head->next;

        p = head;
        while (p)
        {
            p1 = p->next;
            if (p1->random)
            {
                p1->random = p1->random->random;
            }
            p = p1->next;
        }

        p = head;
        while (p)
        {
            p1 = p->next;
            p->next = p1->next;
            if (p1->next)
            {
                p1->next = p1->next->next;
            }
        }
        return result;
    }
};
