#include<iostream>


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
private:
    ListNode* now = nullptr;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        now = head;
        while (head)
        {
            head = head->next;
            length += 1;
        }
        return buildTree(0, length - 1);
    }

    TreeNode* buildTree(int left, int right) {
        if (left == right) 
        {
            TreeNode* root = new TreeNode(now->val);
            now = now->next;
            return root;
        }
        else if (left > right)
        {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode();
        root ->left = buildTree(left, mid - 1);
        root->val = now->val;
        now = now->next;
        root->right = buildTree(mid + 1, right);
        return root;
    }
};
