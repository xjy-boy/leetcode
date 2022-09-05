#include<iostream>


using namespace std;


struct TrieNode
{
    int val;
    TrieNode* child[26] = { nullptr };
    TrieNode()
    {
        val = -1;
    }
};


class MapSum {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode* p = root;
        for (char c : key)
        {
            if (p->child[c - 'a'] == nullptr)
            {
                p->child[c - 'a'] = new TrieNode();
            }
            p = p->child[c - 'a'];
        }
        p->val = val;
    }

    int sum(string prefix) {
        TrieNode* p = root;
        for (char c : prefix)
        {
            if (!p->child[c - 'a'])
            {
                return 0;
            }
            p = p->child[c - 'a'];
        }
        return getSum(p);
    }

    int getSum(TrieNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            result += getSum(root->child[i]);
        }
        if (root->val > 0)
        {
            result += root->val;
        }
        return result;
    }
};

int main()
{
    MapSum m;
    cout << m.sum("adasd") << endl;
    m.insert("apple", 3);
    cout << m.sum("adasd") << endl;
    cout << m.sum("ap") << endl;
    cout << m.sum("apple") << endl;
    m.insert("app", 2);
    cout << m.sum("ap") << endl;
    cout << m.sum("apple") << endl;
}