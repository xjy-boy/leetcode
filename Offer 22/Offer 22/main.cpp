#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* p = head;
		for (int i = 0; i < k; i++)
		{
			p = p->next;
		}
		while (p)
		{
			head = head->next;
			p = p->next;
		}
		return head;
	}
};