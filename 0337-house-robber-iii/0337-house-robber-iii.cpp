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
    unordered_map<TreeNode*,int> dp;
    int rec(TreeNode* root){
        if(!root)
            return 0;
        if(dp.count(root))
            return dp[root];
        int val=root->val;
        if(root->left)
            val+=rec(root->left->left)+rec(root->left->right);
        if(root->right)
            val+=rec(root->right->right)+rec(root->right->left);
        return dp[root]=max(val,rec(root->left)+rec(root->right));
    }
    int rob(TreeNode* root) {
        return rec(root);
    }
};