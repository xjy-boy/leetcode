#include<iostream>
#include<vector>

using namespace std;


class Node {
public:
    int val;
    Node* next;

    Node() {
        val = 0;
        next = NULL;
    }

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr)
        {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }
        Node* p = head->next;
        Node* pre = head;
        
        bool inserted = false;
        do
        {
            // 最大值，最小值节点，检查是否要插入该点
            if (p->val < pre->val)
            {
                if (insertVal >= pre->val || insertVal <= p->val)
                {
                    break;
                }
            }

            if (p->val >= insertVal && pre->val <= insertVal)
            {
                break;
            }

            p = p->next;
            pre = pre->next;
        } while (pre != head);
   

        Node* node = new Node(insertVal);
        pre->next = node;
        node->next = p;
        return head;
    }
};

int main()
{
    Solution solution = Solution();
    Node node1 = Node(1);

    Node node3 = Node(3);
    Node node4 = Node(4);

    //node1.next = &node3;
    node3.next = &node4;
    node4.next = &node3;

    Node* head = &node3;
    solution.insert(head, 2);
}