using ll=long long;
class Solution {
public:
    const ll mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adj(n);
        vector<ll> dist(n,LLONG_MAX),path(n,0);
        dist[0]=0;
        path[0]=1;
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u])
                continue;
            for(auto [v,c]:adj[u]){
                if(c+d>dist[v])
                    continue;
                else if(c+d==dist[v])
                    path[v]=(path[v]+path[u])%mod;
                else{
                    dist[v]=c+d;
                    path[v]=path[u];
                    pq.push({dist[v],v});
                }
            }
        }
        return path.back();
    }
};