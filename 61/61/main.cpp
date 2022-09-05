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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
        {
            return head;
        }
        ListNode* pre = head;
        ListNode* end = head;
        ListNode* p = head;
        int length = 1;
        while (p->next)
        {
            p = p->next;
            length += 1;
        }
        end = p;
        k = k % length;
        if (k == 0)
        {
            return head;
        }
        k = length - k;
        p = head;
        for (int i = 0; i < k; i++)
        {
            pre = p;
            p = p->next;
        }
        pre->next = NULL;
        end->next = head;
        return p;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;
    Solution s;
    s.rotateRight(&node1, 2);
}