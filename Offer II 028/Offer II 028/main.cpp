#include<iostream>
#include<stack>;
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node newHead = Node();
        Node* p = &newHead;
        Node* next = nullptr;
        stack<Node*> nodeStack;
        nodeStack.push(head);
        while (!nodeStack.empty())
        {
            next = nodeStack.top();
            nodeStack.pop();
            p->next = next;
            next->prev = p;
            while (next != nullptr)
            {
                p = next;
                if (next->child != nullptr)
                {
                    if (next->next != nullptr)
                    {
                        nodeStack.push(next->next);
                    }
                    nodeStack.push(next->child);
                    next->child = nullptr;
                    break;
                }
                next = next->next;
            }
        }
        newHead.next->prev = nullptr;
        return newHead.next;
    }
};

int main()
{
    Solution solution = Solution();
    Node node1 = Node();
    Node node2 = Node();
    Node node3 = Node();
    Node node4 = Node();
    Node node5 = Node();
    Node node6 = Node();
    Node node7 = Node();
    Node node8 = Node();
    Node node9 = Node();
    Node node10 = Node();
    Node node11 = Node();
    Node node12 = Node();

    node1.val = 1;
    node1.prev = nullptr;
    node1.next = nullptr;
    node1.child = &node2;

    node2.val = 2;
    node2.prev = nullptr;
    node2.next = nullptr;
    node2.child = &node3;

    node3.val = 3;
    node3.prev = nullptr;
    node3.next = nullptr;
    node3.child = nullptr;

    /*
    node4.val = 4;
    node4.prev = &node3;
    node4.next = &node5;
    node4.child = nullptr;

    node5.val = 5;
    node5.prev = &node4;
    node5.next = &node6;
    node5.child = nullptr;

    node6.val = 6;
    node6.prev = &node5;
    node6.next = nullptr;
    node6.child = nullptr;

    node7.val = 7;
    node7.prev = nullptr;
    node7.next = &node8;
    node7.child = nullptr;

    node8.val = 8;
    node8.prev = &node7;
    node8.next = &node9;
    node8.child = &node11;

    node9.val = 9;
    node9.prev = &node8;
    node9.next = &node10;
    node9.child = nullptr;

    node10.val = 10;
    node10.prev = &node9;
    node10.next = nullptr;
    node10.child = nullptr;

    node11.val = 11;
    node11.prev = nullptr;
    node11.next = &node12;
    node11.child = nullptr;

    node12.val = 12;
    node12.prev = &node11;
    node12.next = nullptr;
    node12.child = nullptr;
    */
    solution.flatten(&node1);
}