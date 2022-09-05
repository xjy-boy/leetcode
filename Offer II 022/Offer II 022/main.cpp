#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* pFast = head;
		ListNode* pSlow = head;

		//第一阶段
		while (pFast != nullptr)
		{
			pFast = pFast->next;
			if (pFast == nullptr)
			{
				return nullptr;
			}
			else
			{
				pFast = pFast->next;
			}
			pSlow = pSlow->next;
			if (pFast == pSlow)
			{
				break;
			}
		}

		//第二阶段
		pSlow = head;
		while (pFast != pSlow)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
};

int main()
{
	Solution solution = Solution();
	ListNode node1 = ListNode(1, nullptr);
	ListNode node2 = ListNode(2, nullptr);
	ListNode node3 = ListNode(3, nullptr);
	ListNode node4 = ListNode(4, nullptr);
	ListNode node5 = ListNode(5, nullptr);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node3;
	cout << solution.detectCycle(&node1)->val << endl;
}


