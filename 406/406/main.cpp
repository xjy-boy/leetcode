#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int h;
    int k;
    Node(int _h, int _k)
    {
        h = _h;
        k = _k;
    }
    friend bool operator<(Node node1, Node node2)
    {
        return node1.h < node2.h;
    }

    friend bool operator>(Node node1, Node node2)
    {
        return node1.h > node2.h;
    }

    friend bool operator==(Node node1, Node node2)
    {
        return node1.h == node2.h;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        priority_queue<Node,vector<Node>,greater<Node>> searchQueue;
        for (int i = 0; i < people.size(); i++)
        {
            people[i].emplace_back(people[i][1]);
        }

        int pre = -1;
        while (!people.empty() || !searchQueue.empty())
        {
            int index = 0;
            while (index < people.size())
            {
                if (people[index][0] <= pre)
                {
                    people[index][1] -= 1;
                }
                if (people[index][1] == 0)
                {
                    int h = people[index][0];
                    int k = people[index][2];
                    people[index] = people.back();
                    people.pop_back();
                    searchQueue.push(Node(h, k));
                }
                else
                {
                    index += 1;
                }
            }
            Node next = searchQueue.top();
            searchQueue.pop();
            ans.push_back({ next.h,next.k });
            pre = next.h;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> p =
    {
        {7,0},
        {4,4},
        {7,1},
        {5,0},
        {6,1},
        {5,2}
    };
    s.reconstructQueue(p);
}