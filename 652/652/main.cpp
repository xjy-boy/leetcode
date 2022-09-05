#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<tuple>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



struct NodeData {
    int val = 0;
    int leftNode = 0;
    int rightNode = 0;
    NodeData(int _v, int _l, int _r) {
        val = _v;
        leftNode = _l;
        rightNode = _r;
    }

    bool operator==(const NodeData& t) const {
        return val == t.val &&
            leftNode == t.leftNode &&
            rightNode == t.rightNode;
    }
};

struct MyHash {
    size_t operator()(const NodeData& t) const {
        return (hash<int>()(t.val) << 24) ^ (hash<int>()(t.leftNode)<<8) ^ hash<int>()(t.rightNode);
    }
};

class Solution {

private:
    unordered_map<NodeData, pair<TreeNode*,int>, MyHash> preIndex;
    unordered_set<TreeNode*> ans;
    int index = 0;

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return { ans.begin(),ans.end() };
    }

    //返回当前节点的序列化值
    //对于空节点的序列化为0
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        NodeData t = NodeData(node->val, dfs(node->left), dfs(node->right));
        auto it = preIndex.find(t);
        if (it == preIndex.end())
        {
            index += 1;
            preIndex[t] = pair<TreeNode*, int>{ node,index };
        }
        else
        {
            ans.insert(preIndex[t].first);
        }
        return preIndex[t].second;
    }
};

int main()
{
    Solution s;
}