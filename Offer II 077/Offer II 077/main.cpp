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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        else if (head->next==nullptr)
        {
            return head;
        }
        else
        {
            ListNode* pre = head;
            ListNode* p1 = head;
            ListNode* p2 = head;
            while (p2 != nullptr)
            {
                pre = p1;
                p1 = p1->next;
                p2 = p2->next;
                if (p2 == nullptr)
                {
                    break;
                }
                p2 = p2->next;
            }
            pre->next = nullptr;
            p1 = sortList(p1);
            p2 = sortList(head);
            return merge(p1, p2);
        }
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode newHead;
        ListNode* p = &newHead;
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val < p2->val)
            {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        }
        while (p1 != nullptr)
        {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }
        while (p2 != nullptr)
        {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
        p->next = nullptr;
        return newHead.next;
    }
};

int main()
{
    ListNode node1(-1);
    ListNode node2(5);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(0);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    Solution s;
    ListNode*p =s.sortList(&node1);
    cout << endl;
}