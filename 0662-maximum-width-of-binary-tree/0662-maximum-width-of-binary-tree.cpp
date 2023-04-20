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
    long long dfs(TreeNode *node,long long level,unsigned long long i,vector<long long> &left){
        if(!node)
            return 0;
        if(left.size()<=level)
            left.push_back(i);
        return max({(long long)(i+1LL-left[level]),dfs(node->left,level+1,2LL*i,left),dfs(node->right,level+1,2LL*i+1,left)});
    }
    int widthOfBinaryTree(TreeNode* root) {
        vector<long long> left;
        return dfs(root,0,1,left);
    }
};