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
    ListNode* reverseList(ListNode* head) {
		ListNode newHead = ListNode();
		ListNode* p = head;
		ListNode* pre = head;

		while (p != nullptr)
		{
			pre = p->next;
			p->next = newHead.next;
			newHead.next = p;
			p = pre;
		}
		return newHead.next;
    }
};

int main()
{
    Solution solution = Solution();
	ListNode node1 = ListNode(1);
	ListNode node2 = ListNode(2);
	ListNode node3 = ListNode(3);
	ListNode node4 = ListNode(4);
	ListNode node5 = ListNode(5);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	solution.reverseList(&node1);
}