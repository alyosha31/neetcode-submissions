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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& iter, int lower, int upper) {
        // boundary conditions
        if(upper<lower) {
            iter--;
            return NULL;
        }
        // create root with preorder[iter]
        TreeNode* root = new TreeNode(preorder[iter]);
        // find preorder[iter] in inorder
        int i = lower;
        for(; i<=upper && inorder[i] != preorder[iter]; i++) {
        }
        if(i>upper) {
            iter--;
            return NULL;
        }
        // connect left
        root->left = build(preorder, inorder, ++iter, lower, i-1);
        // connect right
        root->right = build(preorder, inorder, ++iter, i+1, upper);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        int j = preorder.size()-1;
        int iter = 0;
        return build(preorder, inorder, iter, i, j);
    }
};
