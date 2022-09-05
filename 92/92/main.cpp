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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
        {
            return head;
        }
        ListNode* p = head;
        ListNode* last;
        ListNode* pre = p;
        ListNode* next;
        ListNode newHead(0);
        for (int i = 0; i < left - 1; i++)
        {
            pre = p;
            p = p->next;
        }
        if (left == 1)
        {
            pre = &newHead;
        }
        last = p;
        for (int i = left; i <= right; i++)
        {
            next = p->next;
            p->next = newHead.next;
            newHead.next = p;
            p = next;
        }
        last->next = p;
        if (left == 1)
        {
            return newHead.next;
        }
        else
        {
            pre->next = newHead.next;
            return head;
        }
    }
};

int main()
{
    Solution s;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    s.reverseBetween(&node1, 1, 5);
}