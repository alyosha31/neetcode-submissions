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

    pair<int, int> isValid(TreeNode* root, bool& ans) {
        if(!root) return {INT_MAX, INT_MIN};
        auto left = isValid(root->left, ans);
        auto right = isValid(root->right, ans);
        int leftMax = left.second;
        int rightMin = right.first;
        if(root->val <= leftMax || root->val>=rightMin) ans = false;
        int minimum = min(root->val, left.first);
        int maximum = max(root->val, right.second);
        return make_pair(minimum, maximum); 
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        pair<int, int> rando = isValid(root, ans);
        return ans;
    }
};
