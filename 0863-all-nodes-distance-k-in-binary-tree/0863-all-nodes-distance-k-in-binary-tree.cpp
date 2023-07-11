/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,vector<TreeNode*>> mp;
    vector<int> ans;
    void createGraph(TreeNode* cur, TreeNode* par=nullptr){
        if(!cur)
            return;
        if(par){
            mp[cur].push_back(par);
            mp[par].push_back(cur);
        }
        createGraph(cur->left,cur);
        createGraph(cur->right,cur);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!k)
            return {target->val};
        createGraph(root);
        queue<TreeNode*> q;
        set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int d=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto u=q.front();
                q.pop();
                for(auto v:mp[u]){
                    if(vis.count(v))
                        continue;
                    vis.insert(v);
                    if(d<k)
                        q.push(v);
                    else
                        ans.push_back(v->val);
                }
            }
            d++;
        }
        return ans;
    }
};