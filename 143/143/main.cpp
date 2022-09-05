#include<iostream>
#include<stack>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> listStack;
        ListNode* p = head;
        ListNode* q = nullptr;
        int length = 0;
        while (p != nullptr)
        {
            length += 1;
            listStack.push(p);
            p = p->next;
        }

        p = head;
        for (int i = 0; i < (length - 1) / 2; i++)
        {
            q = listStack.top();
            listStack.pop();
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        listStack.top()->next = nullptr;
    }
};