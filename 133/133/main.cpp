#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return NULL;
        }
        queue<Node*> buildQueue;
        queue<Node*> originalQueue;
        unordered_map<int, Node*> nodeMap;
        Node* newNode = new Node(node->val);
        buildQueue.push(newNode);
        originalQueue.push(node);
        nodeMap[node->val] = newNode;
        while (!buildQueue.empty())
        {
            Node* now = buildQueue.front();
            Node* origin = originalQueue.front();
            buildQueue.pop();
            originalQueue.pop();
            for (Node* next : origin->neighbors)
            {
                if (nodeMap.count(next->val))
                {
                    now->neighbors.push_back(nodeMap[next->val]);
                }
                else
                {
                    Node* p = new Node(next->val);
                    now->neighbors.push_back(p);
                    nodeMap[next->val] = p;
                    buildQueue.push(p);
                    originalQueue.push(next);
                }
            }
        }
        return newNode;
    }
};

int main()
{
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    node1.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node4);

    node2.neighbors.push_back(&node1);
    node2.neighbors.push_back(&node3);

    node3.neighbors.push_back(&node2);
    node3.neighbors.push_back(&node4);

    node4.neighbors.push_back(&node1);
    node4.neighbors.push_back(&node3);

    Solution s;
    s.cloneGraph(&node1);
}