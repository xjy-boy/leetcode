#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode templeHead(0);
		templeHead.next = head;
		ListNode* pre = &templeHead;
		while (pre->next)
		{
			if (pre->next->val == val)
			{
				pre->next = pre->next->next;
				break;
			}
			pre = pre->next;
		}
		return templeHead.next;
	}
};