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
    bool isSame(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        if(!t1->left && !t1->right && !t2->left && !t2->right) {
            if(t1->val == t2->val) return true;
            return false;
        }
        if(!t1->left && !t1->right) return false;
        if(!t2->left && !t2->right) return false;
        return (t1->val == t2->val) && (isSame(t1->left, t2->left) && (isSame(t1->right, t2->right)));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(!root) return false;
        if(!subRoot) return false;
        bool ans = isSame(root, subRoot);
        return ans || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
    }
};
