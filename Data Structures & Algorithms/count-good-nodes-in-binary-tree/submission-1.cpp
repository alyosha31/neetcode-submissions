/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void good(TreeNode* root, int maxSoFar, int& count) {
        if(!root) return;
        if(maxSoFar<=root->val) count++; 
        maxSoFar = max(maxSoFar, root->val);
        good(root->left, maxSoFar, count);
        good(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int count = 0;
        good(root, INT_MIN, count);   
        return count;
    }
};
