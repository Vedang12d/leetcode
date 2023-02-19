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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp={root->val};
        ans.push_back(temp);
        int ct=2;
        while(!q.empty()){
            int n=q.size();
            temp.clear();
            while(n--){
                auto node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            if(ct%2==0)
                reverse(temp.begin(),temp.end());
            ct++;
            ans.push_back(temp);
        }
        ans.pop_back();
        return ans;
    }
};