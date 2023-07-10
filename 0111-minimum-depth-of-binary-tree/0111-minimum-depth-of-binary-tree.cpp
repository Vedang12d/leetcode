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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto u=q.front();
                q.pop();
                if(!u->left and !u->right)
                    return ans;
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
            ans++;
        }
        return ans;
    }
};