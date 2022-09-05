#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* makeList(vector<int> data)
{
	ListNode* head = new ListNode(data[0], nullptr);
	ListNode* p = head;
	for (int i = 1; i < data.size(); i++)
	{
		p->next = new ListNode(data[i], nullptr);
		p = p->next;
	}
	return head;
}

void display(ListNode* head)
{
	ListNode* p = head;
	while (p != nullptr)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void free(ListNode* head)
{
	ListNode* p = head;
	ListNode* pre = head;
	while (p != nullptr)
	{
		pre = p;
		p = p->next;
		delete pre;
	}
}

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode newHead = ListNode(0,head);
		ListNode* pre = &newHead;
		ListNode* p = head;
		ListNode* end = head;
		for (int i = 0; i < n; i++)
		{
			end = end->next;
		}
		while (end != nullptr)
		{
			p = p->next;
			end = end->next;
			pre = pre->next;
		}
		pre->next = p->next;
		//delete p;
		return newHead.next;
	}
};

int main()
{
	Solution solution = Solution();
	vector<int> nums = { 1,2 };
	ListNode* head = makeList(nums);
	display(head);
	head = solution.removeNthFromEnd(head, 2);
	display(head);
	free(head);
}