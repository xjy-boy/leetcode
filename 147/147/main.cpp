#include<iostream>

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode newHead(0);
        ListNode* p = head;
        ListNode* p2 = head;

        newHead.next = p;
        p = p->next;
        head->next = NULL;
        while (p != NULL)
        {

            ListNode* pre = &newHead;
            ListNode* next = newHead.next;
            while (next != NULL && next->val < p->val)
            {
                pre = next;
                next = next->next;
            }

            pre->next = p;
            p = p->next;
            pre->next->next = next;
        }
        return newHead.next;
    }
};
