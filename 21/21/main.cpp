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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode newHead(0);
		ListNode* pre = &newHead;
		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				pre->next = list1;
				pre = pre->next;
				list1 = list1->next;
			}
			else
			{
				pre->next = list2;
				pre = pre->next;
				list2 = list2->next;
			}
		}
		if (list1)
		{
			pre->next = list1;
		}
		else
		{
			pre->next = list2;
		}
		return newHead.next;
	}
};

int main()
{

}