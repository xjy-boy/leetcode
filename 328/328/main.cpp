#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode newHead1;
        ListNode newHead2;
        ListNode* p = head;
        ListNode* p1 = &newHead1;
        ListNode* p2 = &newHead2;
        while (p)
        {
            p1->next = p;
            p1 = p1->next;

            p = p->next;
           
            if (p)
            {
                p2->next = p;
                p2 = p2->next;
                p = p->next;
            }
        }
        p2->next = NULL;
        p1->next = newHead2.next;
        return newHead1.next;
    }
};