#include<iostream>
#include<stack>
#include<vector>
using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    void reorderList(ListNode* head) {
        stack<ListNode*> listStack;
        ListNode* p = head;
        ListNode* q = nullptr;
        int length = 0;
        while (p != nullptr)
        {
            length += 1;
            listStack.push(p);
            p = p->next;
        }

        p = head;
        for (int i = 0; i < (length-1) / 2; i++)
        {
            q = listStack.top();
            listStack.pop();
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        listStack.top()->next = nullptr;
    }
};

int main()
{
    Solution solution = Solution();
    ListNode* head = makeList({1});
    solution.reorderList(head);
    display(head);
}