class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool> &vis,int u,int &ct){
        vis[u]=1;
        for(auto v:adj[u]){
            if(vis[v])
                continue;
            dfs(adj,vis,v,++ct);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            int ct=1;
            dfs(adj,vis,i,ct);
            v.push_back(ct);
        }
        long long ans=0,sum=accumulate(v.begin(),v.end(),0LL);
        for(auto &x:v){
            sum-=x;
            ans+=x*sum;
        }
        return ans;
    }
};