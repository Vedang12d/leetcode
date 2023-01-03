class Solution {
public:
    bool dfs(int node,int time,vector<vector<int>> &adj,vector<bool> &vis,unordered_map<int,int> &path){
        vis[node]=1;
        path[node]=time;
        if(!node)
            return 1;
        for(auto child:adj[node]){
            if(!vis[child]&&dfs(child,time+1,adj,vis,path))
                return 1;
        }
        path.erase(node);
        return 0;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>> adj(n);
        for(auto ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        vector<bool> vis(n,0);
        unordered_map<int,int> path;
        dfs(bob,0,adj,vis,path);
        queue<array<int,3>> q;
        q.push({0,0,0});
        vis.assign(n,0);
        int ans=INT_MIN;
        while(!q.empty()){
            auto [node,time,money]=q.front();
            q.pop();
            vis[node]=1;
            if(!path.count(node)||time<path[node])
                money+=amount[node];
            else if(time==path[node])
                money+=amount[node]/2;
            if(adj[node].size()==1&&node)
                ans=max(ans,money);
            for(auto child:adj[node])
                if(!vis[child])
                    q.push({child,time+1,money});                
        }
        return ans;
    }
};