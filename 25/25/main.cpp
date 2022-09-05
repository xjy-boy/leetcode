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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode newHead(0);
        ListNode* pre = &newHead;
        ListNode* nowHead = pre;
        ListNode* p = head;
        ListNode* last = p;
        while (nowHead && p)
        {
            int i = 0;
            for (int i = 0; i < k; i++)
            {
                pre = p;
                p = p->next;
                pre->next = nowHead->next;
                nowHead->next = pre;
                if (!p && i!=k-1)
                {
                    //最后一组不足k
                    p = nowHead->next;
                    nowHead->next = NULL;
                    while (p)
                    {
                        pre = p;
                        p = p->next;
                        pre->next = nowHead->next;
                        nowHead->next = pre;
                    }
                    break;
                }
            }
            nowHead = last;
            last = p;
        }
        return newHead.next;
    }
};

int main()
{
    vector<ListNode> list;
    for (int i = 1; i <= 2; i++)
    {
        list.emplace_back(ListNode(i));
    }

    for (int i = 1; i <= 1; i++)
    {
        list[i - 1].next = &list[i];
    }
    Solution s;
    s.reverseKGroup(&list[0], 2);
}