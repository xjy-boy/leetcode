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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
        {
            return head;
        }
        ListNode newHead(0);
        newHead.next = head;
        ListNode* pre = &newHead;
        ListNode* p = head;
        ListNode* next = head->next;
        while (next)
        {
            if (next->val != p->val)
            {
                pre = p;
                p = next;
                next = next->next;
            }
            else
            {
                int val = next->val;
                while (next && next->val == val)
                {
                    next = next->next;
                }
                pre->next = next;
                if (next)
                {
                    p = next;
                    next = next->next;
                }
            }
        }
        return newHead.next;
    }
};