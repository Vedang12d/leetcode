class Solution {
public:
    vector<int> dp;
    int dfs(int u,vector<vector<int>> &graph,vector<bool> &vis){
        if(dp[u]!=-1)
            return dp[u];
        if(vis[u])
            return dp[u]=0;
        vis[u]=1;
        for(auto &v:graph[u]){
            if(!dfs(v,graph,vis))
                return dp[u]=0;
        }
        return dp[u]=1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        dp.resize(n,-1);
        for(int i=0;i<n;i++){
            if(dp[i]==-1){
                vector<bool> vis(n);
                dfs(i,graph,vis);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(dp[i])
                ans.push_back(i);
        return ans;
    }
};