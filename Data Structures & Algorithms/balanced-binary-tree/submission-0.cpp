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
    int height(TreeNode* root, bool& answer) {
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 1;
        int heightL = height(root->left, answer);
        int heightR = height(root->right, answer);
        if(abs(heightL-heightR)>1) answer = false;
        return 1 + max(heightL, heightR);
    }
    bool isBalanced(TreeNode* root) {
        bool answer = true;
        int heightTree = height(root, answer);
        return answer;
    }
};
