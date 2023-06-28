class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> memo(n);
        memo[start]=1.0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            for(auto &v:adj[u]){
                if(memo[u]*v.second<=memo[v.first])
                    continue;
                q.push(v.first);
                memo[v.first]=memo[u]*v.second;
            }
        }
        return memo[end];
    }
};