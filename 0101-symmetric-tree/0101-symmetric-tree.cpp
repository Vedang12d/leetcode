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
    bool isSymmetric(TreeNode* rootl,TreeNode* rootr) {
        if(!rootl&&!rootr)
            return 1;
        if(!rootl||!rootr||rootl->val!=rootr->val)
            return 0;
        return isSymmetric(rootl->right,rootr->left)&&isSymmetric(rootr->right,rootl->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left,root->right);
    }
};