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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head1;
        ListNode head2;
        ListNode ans;
        ListNode* p = l1;
        ListNode* next = l1;
        int c = 0;
        while (p)
        {
            next = p->next;
            p->next = head1.next;
            head1.next = p;
            p = next;
        }
        p = l2;
        while (p)
        {
            next = p->next;
            p->next = head1.next;
            head2.next = p;
            p = next;
        }
        ListNode* p1 = head1.next;
        ListNode* p2 = head2.next;
        p = &ans;
        while (p1 && p2)
        {
            int result = p1->val + p2->val;
            c = result / 10;
            result = result % 10;
            p->next = new ListNode(result);
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2)
        {
            p1 = p2;
        }
        while (p1)
        {
            int result = p1->val;
            c = result / 10;
            result = result % 10;
            p->next = new ListNode(result);
            p = p->next;
            p1 = p1->next;
        }
        if (c != 0)
        {
            p->next = new ListNode(c);
        }
        return ans.next;
    }
};
