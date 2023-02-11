class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<array<int,2>>> adj(n);
        for(auto &e:redEdges)
            adj[e[0]].push_back({e[1],0});
        for(auto &e:blueEdges)
            adj[e[0]].push_back({e[1],1});
        vector<int> ans(n,-1);
        queue<array<int,3>> q;
        q.push({0,0,-1});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(ans[t[0]]==-1)
                ans[t[0]]=t[1];
            for(auto &e:adj[t[0]]){
                if(t[2]!=e[1]&&e[0]!=-1){
                    q.push({e[0],t[1]+1,e[1]});
                    e[0]=-1;
                }                
            }
        }
        return ans;
    }
};