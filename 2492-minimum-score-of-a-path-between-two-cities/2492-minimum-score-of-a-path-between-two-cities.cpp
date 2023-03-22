class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n+1);
        vector<vector<array<int,2>>> adj(n+1);
        for(auto &e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        queue<int> q;
        q.push(1);
        vis[1]=1;
        int ans=INT_MAX;
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            for(auto &[v,d]:adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
                ans=min(ans,d);
            }
        }
        return ans;
    }
};