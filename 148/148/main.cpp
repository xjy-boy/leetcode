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
    ListNode* sortList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            if (!fast)
            {
                break;
            }
            slow = slow->next;
        }
        if (fast == slow)
        {
            return head;
        }
        else
        {
            ListNode* p1 = head;
            ListNode* p2 = slow->next;
            slow->next = NULL;
            p1 = sortList(p1);
            p2 = sortList(p2);
            return  mergesort(p1, p2);
        }
    }


    ListNode* mergesort(ListNode *head1,ListNode *head2)
    {
        ListNode newHead(0);
        ListNode* p = &newHead;
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                p->next = head1;
                head1 = head1->next;
                p = p->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
                p = p->next;
            }
        }
        if (head1)
        {
            p->next = head1;
        }
        else
        {
            p->next = head2;
        }
        return newHead.next;
    }
};

int main()
{
    Solution s;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    node4.next = &node2;
    node2.next = &node1;
    node1.next = &node3;
    s.sortList(&node4);
}