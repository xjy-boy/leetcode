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
private:
    ListNode* _head;
public:
    Solution(ListNode* head) {
        _head = head;
    }

    int getRandom() {
        ListNode* p = _head;
        int num = 1;
        int ans = 0;
        while (p)
        {
            if (rand() % num == 0)
            {
                ans = p->val;
            }
            p = p->next;
            num += 1;
        }
        return ans;
    }
};