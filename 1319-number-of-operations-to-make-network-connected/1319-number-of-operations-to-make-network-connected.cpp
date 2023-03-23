class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool> &vis,int u){
        vis[u]=1;
        for(auto &v:adj[u]){
            if(vis[v])
                continue;
            dfs(adj,vis,v);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto &e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            dfs(adj,vis,i);
            ans++;
        }
        return ans-1;
    }
};