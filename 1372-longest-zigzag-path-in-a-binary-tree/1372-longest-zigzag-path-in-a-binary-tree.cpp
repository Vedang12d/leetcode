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
    int ans=0;
    void dfs(TreeNode* root, int step, bool left){
        if(!root)
            return;
        ans=max(step,ans);
        if(left){
            dfs(root->right,step+1,false);
            dfs(root->left,1,true);
        }else{
            dfs(root->left,step+1,true);
            dfs(root->right,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,true), dfs(root,0,false);
        return ans;
    }
};