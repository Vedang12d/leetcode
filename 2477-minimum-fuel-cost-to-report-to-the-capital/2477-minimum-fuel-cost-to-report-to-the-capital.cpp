class Solution {
public:
    int dfs(vector<vector<int>> &adj,int &seats,int u,int prev,long long &ans){
        int people=1;
        for(auto v:adj[u]){
            if(v==prev)
                continue;
            people+=dfs(adj,seats,v,u,ans);
        }
        if(u)
            ans+=(people+seats-1)/seats;
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adj(roads.size()+1);
        long long ans=0;
        for(auto e:roads){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(adj,seats,0,0,ans);
        return ans;
    }
};