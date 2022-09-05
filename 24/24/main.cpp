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
    ListNode* swapPairs(ListNode* head) {
        if (!head)
        {
            return head;
        }
        ListNode newhead(0);
        ListNode* pre = &newhead;
        ListNode* p = head;
        ListNode* nextp = head->next;

        newhead.next = head;
        while (p && p->next)
        {
            nextp = p->next;

            pre->next = nextp;
            p->next = nextp->next;
            nextp->next = p;
            
            pre = p;
            p = p->next;    
        }

        return newhead.next;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    Solution s;
    s.swapPairs(&node1);
}