#include<iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (!headA || !headB)
		{
			return NULL;
		}

		ListNode* p1 = headA;
		ListNode* p2 = headB;
		ListNode* p;
		while (p1 && p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		if (!p1)
		{
			p = p2;
			p1 = headA;
			p2 = headB;
			while (p)
			{
				p = p->next;
				p2 = p2->next;
			}
		}
		else
		{
			p = p1;
			p1 = headA;
			p2 = headB;
			while (p)
			{
				p = p->next;
				p1 = p1->next;
			}
		}

		while (p1 && p2)
		{
			if (p1 == p2)
			{
				return p1;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return NULL;
	}
};
