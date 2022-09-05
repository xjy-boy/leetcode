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
        ListNode* pre = head;
        ListNode* p = head->next;
        while (p)
        {
            if (p->val == pre->val)
            {
                p = p->next;
                pre->next = p;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};