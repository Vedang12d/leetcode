class Solution {
public:
    vector<int> dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &ans,string &label){
        vector<int> ct(26,0);
        for(auto child:adj[node]){
            if(child==parent)
                continue;
            auto v=dfs(child,node,adj,ans,label);
            for(int i=0;i<26;i++)
                ct[i]+=v[i];
        }
        ct[label[node]-'a']++;
        ans[node]=ct[label[node]-'a'];
        return ct;        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n,0);
        dfs(0,-1,adj,ans,labels);
        return ans;
    }
};