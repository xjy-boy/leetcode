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
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}
		int lengthA = 0;
		int lengthB = 0;
		int c = 0;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while (pA->next != nullptr)
		{
			pA = pA->next;
			lengthA += 1;
		}
		while (pB->next != nullptr)
		{
			pB = pB->next;
			lengthB += 1;
		}
		if (pA != pB)
		{
			return nullptr;
		}
		lengthA += 1;
		lengthB += 1;
		if (lengthA > lengthB)
		{
			pA = headA;
			pB = headB;
			c = lengthA - lengthB;
		}
		else
		{
			pB = headA;
			pA = headB;
			c = lengthB - lengthA;
		}
		for (int i = 0; i < c; i++)
		{
			pA = pA->next;
		}
		while (pA != pB)
		{
			pA = pA->next;
			pB = pB->next;
		}
		return pA;
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
	ListNode node6 = ListNode(6);
	ListNode node7 = ListNode(7);
	ListNode node8 = ListNode(8);
	node1.next = &node2;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node2.next = &node6;
	node6.next = &node7;
	node7.next = &node8;
	cout << solution.getIntersectionNode(&node1, nullptr)->val << endl;
}