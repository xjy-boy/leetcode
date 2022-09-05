#include<iostream>
#include"List.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //虚拟头节点
        ListNode newHead = ListNode();
        newHead.next = head;
        ListNode* p1 = &newHead;
        ListNode* p2 = &newHead;
        ListNode* mid = p1;
        //寻找中间节点
        while (p2 !=nullptr && p2->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
            p2 = p2->next;
        }
        mid = p1;
        p1 = p1->next;
        mid->next = nullptr;
        //头插法反转p1之后的链表
        while (p1 != nullptr)
        {
            p2 = p1->next;
            p1->next = mid->next;
            mid->next = p1;
            p1 = p2;
        }

        //反转之后开始从头比较
        p1 = head;
        p2 = mid->next;
        while (p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                return false;
            }
            else
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution = Solution();
    ListNode* head = makeList({ 1 });
    cout << solution.isPalindrome(head) << endl;
}