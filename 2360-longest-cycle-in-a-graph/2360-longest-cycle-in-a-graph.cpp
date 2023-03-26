class Solution {
public:
    int ans=-1;
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int node,int ct=0){
        vis[node]=1;
        for(auto &v:adj[node]){
            if(!vis[v])
                dfs(adj,vis,v,ct+1);
            else if(vis[v]==1)
                ans=max(ans,ct+1);
        }
        vis[node]=2;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]==-1)
                continue;
            adj[edges[i]].push_back(i);
        }
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            dfs(adj,vis,i);
        }
        return ans;
    }
};