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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mp, int& iter, int lower, int upper) {
        // boundary conditions
        if(upper<lower) {
            return NULL;
        }
        // create root with preorder[iter]
        TreeNode* root = new TreeNode(preorder[iter]);
        // find preorder[iter] in inorder
        int i = mp[preorder[iter]];
        if(i>upper) {
            return NULL;
        }
        iter++;
        // connect left
        root->left = build(preorder, inorder, mp, iter, lower, i-1);
        // connect right
        root->right = build(preorder, inorder, mp, iter, i+1, upper);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        int j = preorder.size()-1;
        int iter = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, mp, iter, i, j);
    }
};
