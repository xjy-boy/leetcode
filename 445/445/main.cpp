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
        
        int length1 = 0;
        int length2 = 0;
        ListNode* p = l1;
        while (p)
        {
            length1 += 1;
            p = p->next;
        }
        p = l2;
        while (p)
        {
            length2 += 1;
            p = p->next;
        }
        ListNode ans(0);
        p = &ans;
        for (int i = 0; i < max(length1, length2); i++)
        {
            p->next = new ListNode(0);
            p = p->next;
        }
        int dif = length1 - length2;
        int t = 0;
        if (dif > 0)
        {
            t = add(ans.next, l1, l2, dif);
        }
        else
        {
            t = add(ans.next, l2, l1, -dif);
        }
        if (t != 0)
        {
            ListNode* newHead = new ListNode(t);
            newHead->next = ans.next;
            p = newHead;
        }
        else
        {
            p = ans.next;
        }
        return p;
    }

    int add(ListNode* ans,ListNode* l1, ListNode* l2,int dif) {
        if (!ans)
        {
            return 0;
        }
        else
        {
            int t = 0;
            if (dif > 0)
            {
                t = add(ans->next, l1->next, l2, dif - 1);
                ans->val = l1->val + t;
                t = ans->val / 10;
                ans->val = ans->val % 10;
            }
            else
            {
                t = add(ans->next, l1->next, l2->next, -1);
                ans->val = l1->val + l2->val + t;
                t = ans->val / 10;
                ans->val = ans->val % 10;
            }
            return t;
        }
    }
};