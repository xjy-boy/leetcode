#include<iostream>

using namespace std;
 
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode newHead(0);
        ListNode* p = NULL;
        while (head)
        {
            p = head->next;
            head->next = newHead.next;
            newHead.next = head;
            head = p;
        }
        return newHead.next;
    }
};