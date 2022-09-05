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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode result;
        result.next = head;
        ListNode* pre = &result;
        ListNode* next = pre->next;
        while (next) {
            if (next->val == val) {
                pre->next = next->next;
                next = pre->next;
            }
            else {
                pre = pre->next;
                next = next->next;
            }
        }
        return result.next;
    }
};

void display(ListNode* head) {
    ListNode* p = head;
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
}
bool check(ListNode* head, int val) {
    ListNode* p = head;
    while (p) {
        if (p->val == val) {
            return false;
        }
        p = p->next;
    }
    return true;
}

int main() {
    Solution solution = Solution();
    vector<int> data = { 1,2,6,3,4,5,6 };
    int val = 6;
    ListNode* p = new ListNode(data[0]);
    ListNode* head = p;
    for (int i = 0; i < data.size() - 1; i++) {
        p->next = new ListNode(data[i+1]);
        p = p->next;
    }
    display(head);
    head = solution.removeElements(head, val);
    display(head);
    while (head) {
        ListNode* pre = head;
        head = head->next;
        free(pre);
    }
}