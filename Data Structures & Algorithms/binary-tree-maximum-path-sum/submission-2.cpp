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
    int dfs(TreeNode* root, int& ans) {
        // boundary conditions
        if(!root) return 0;
        //fron the left
        int left = max(0, dfs(root->left, ans));
        //from the right
        int right = max(0, dfs(root->right, ans));
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int random = dfs(root, ans);
        return ans;
    }
};
