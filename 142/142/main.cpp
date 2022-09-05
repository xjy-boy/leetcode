#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

using namespace  std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && slow)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }


        if (!fast || !fast->next)
        {
            return NULL;
        }
        else
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};