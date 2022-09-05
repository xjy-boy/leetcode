#include<iostream>
#include"List.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //����ͷ�ڵ�
        ListNode newHead = ListNode();
        newHead.next = head;
        ListNode* p1 = &newHead;
        ListNode* p2 = &newHead;
        ListNode* mid = p1;
        //Ѱ���м�ڵ�
        while (p2 !=nullptr && p2->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
            p2 = p2->next;
        }
        mid = p1;
        p1 = p1->next;
        mid->next = nullptr;
        //ͷ�巨��תp1֮�������
        while (p1 != nullptr)
        {
            p2 = p1->next;
            p1->next = mid->next;
            mid->next = p1;
            p1 = p2;
        }

        //��ת֮��ʼ��ͷ�Ƚ�
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