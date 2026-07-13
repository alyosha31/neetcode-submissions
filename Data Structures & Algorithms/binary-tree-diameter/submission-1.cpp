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
    int diameter(TreeNode* root, int& path) {
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 1; 
        int leftD = diameter(root->left, path);
        int rightD = diameter(root->right, path);
        int dist = 1 + leftD + rightD;
        path = max(path, dist); 
        return 1 + max(leftD, rightD);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int path = 0;
        int dist = diameter(root, path);
        return path>0?path-1:0;
    }
};
