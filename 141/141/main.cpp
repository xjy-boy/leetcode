#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

using namespace  std;

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head)
        {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && slow)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};