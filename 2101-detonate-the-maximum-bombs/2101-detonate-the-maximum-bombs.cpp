using ll=long long;
class Solution {
public:
    vector<vector<int>> adj;
    int dfs(int u,vector<bool> &vis){
        vis[u]=1;
        int res=1;
        for(auto &v:adj[u]){
            if(!vis[v])
                res+=dfs(v,vis);
        }
        return res;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        adj.resize(n);
        for(int i=0;i<n;i++){
            ll x1=bombs[i][0], y1=bombs[i][1], r1=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                ll x2=abs(x1-bombs[j][0]), y2=abs(y1-bombs[j][1]);
                if(x2*x2+y2*y2<=r1*r1)
                    adj[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<bool> vis(n);
            ans=max(ans,dfs(i,vis));
        }
        return ans;
    }
};