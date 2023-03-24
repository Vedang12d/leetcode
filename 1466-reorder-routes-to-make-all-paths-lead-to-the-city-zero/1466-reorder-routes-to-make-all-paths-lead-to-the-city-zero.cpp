class Solution {
public:
    int dfs(vector<vector<int>> &adj,int u,int p){
        int count=0;
        for(auto v:adj[u]){
            if(abs(v)==p)
                continue;
            count+=dfs(adj,abs(v),u)+(v>0);
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(-e[0]);
        }
        return dfs(adj,0,-1);
    }
};