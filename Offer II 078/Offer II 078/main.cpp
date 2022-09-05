#include<iostream>
#include<vector>
#include<queue>

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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto cmp = []( ListNode*  p1,ListNode* p2){return p1->val > p2->val;};
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
		for (ListNode* p : lists)
		{
			if (p != nullptr)
			{
				q.push(p);
			}
		}
		ListNode newNode;
		ListNode* p = &newNode;
		while (!q.empty())
		{
			ListNode* next = q.top();
			q.pop();
			p->next = next;
			p = p->next;
			if (next->next != nullptr)
			{
				q.push(next->next);
			}
		}
		p = p->next;
		return newNode.next;
	}
};

int main()
{
	ListNode node1(1);
	ListNode node2(4);
	ListNode node3(5);
	
	ListNode node4(1);
	ListNode node5(3);
	ListNode node6(4);
	node1.next = &node2;
	node2.next = &node3;
	
	node4.next = &node5;
	node5.next = &node6;
	vector<ListNode*> lists = { &node1,&node4 };
	Solution s;
	s.mergeKLists(lists);
}