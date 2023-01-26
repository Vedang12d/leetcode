class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> cost(n,INT_MAX);
        for(auto &f:flights)
            adj[f[0]].push_back({f[1],f[2]});
        queue<pair<int,int>> q;
        int ans=INT_MAX;
        q.push({src,0});
        cost[src]=0;
        k++;
        while(k-- && !q.empty()){
            int size=q.size();
            while(size--){
                auto [u,dis]=q.front();
                q.pop();
                for(auto v:adj[u]){
                    if(v.second+dis>ans)
                        continue;
                    if(v.first==dst)
                        ans=min(ans,dis+v.second);
                    if(v.second+dis<cost[v.first]){
                        cost[v.first]=v.second+dis;
                        q.push({v.first,cost[v.first]});
                    }
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};