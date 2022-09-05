#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int, int> sumMap;
    int maxCount = 0;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxCount = 0;
        getSum(root);
        vector<int> ans;
        for (auto it = sumMap.begin(); it != sumMap.end(); it++)
        {
            if (it->second == maxCount)
            {
                ans.emplace_back(it->first);
            }
        }
        return ans;
    }

    int getSum(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = root->val;
        ans += getSum(root->left);
        ans += getSum(root->right);
        int count = 1;
        if (sumMap.count(ans))
        {
            count = sumMap[ans] + 1;
        }
        
        sumMap[ans] = count;
        if (count > maxCount)
        {
            maxCount = count;
        }
        return ans;
    }
};

int main()
{
    TreeNode node1(5);
    TreeNode node2(2);
    TreeNode node3(-5);
    node1.left = &node2;
    node1.right = &node3;
    Solution s;
    s.findFrequentTreeSum(&node1);
}