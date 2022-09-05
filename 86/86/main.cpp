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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode littleNode(0);
        ListNode bigNode(0);
        ListNode* p1 = &littleNode;
        ListNode* p2 = &bigNode;
        ListNode* p = head;
        while (p)
        {
            if (p->val >= x)
            {
                p2->next = p;
                p2 = p2->next;
                p = p->next;
            }
            else
            {
                p1->next = p;
                p1 = p1->next;
                p = p->next;
            }
        }
        p1->next = bigNode.next;
        p2->next = NULL;
        return littleNode.next;
    }
};

int main()
{
    vector<ListNode> list;
    list.push_back(ListNode(1));
    list.push_back(ListNode(4));
    list.push_back(ListNode(3));
    list.push_back(ListNode(2));
    list.push_back(ListNode(5));
    list.push_back(ListNode(2));
    for (int i = 0; i < list.size() - 1; i++)
    {
        list[i].next = &list[i + 1];
    }
    Solution s;
    s.partition(&list[0], 3);
}