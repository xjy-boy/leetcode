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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* p = l1;
        ListNode* pre = l1;
        ListNode* q = l2;
        while (p && q)
        {
            int now = p->val + q->val + c;
            c = now / 10;
            now = now % 10;
            p->val = now;
            q->val = now;
            pre = p;
            p = p->next;
            q = q->next;
        }

        if (!p && q)
        {
            p = q;
            l1 = l2;
        }
        while (p)
        {
            if (c == 0)
            {
                break;
            }
            else
            {
                int now = p->val + c;
                c = now / 10;
                now = now % 10;
                p->val = now;
                pre = p;
                p = p->next;
            }
        }
        if (c != 0)
        {
            pre->next = new ListNode(c);
        }
        return l1;
    }
};

int main()
{
    ListNode l1(5);
    ListNode l2(5);

    Solution s;
    s.addTwoNumbers(&l1, &l2);
}