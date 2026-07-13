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
    void traversal(TreeNode* root, int count, vector<vector<int>> &v) {
        if(root == NULL) return;
        if(v.size() < count+1) {
            vector<int> temp;
            v.push_back(temp);
        }
        v[count].push_back(root->val);
        traversal(root->left, count+1, v);
        traversal(root->right, count+1, v);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traversal(root, 0, ans);
        return ans;
    }
};
