class Solution {
public:
    vector<vector<int>> adj;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,0),instack(numCourses,0);
        adj.resize(numCourses);
        for(auto x:prerequisites)
            adj[x[0]].push_back(x[1]);
        for(int i=0;i<numCourses;i++)
            if(cyclic(i,vis,instack))
                return 0;
        return 1;
    }
    bool cyclic(int node,vector<bool> &vis,vector<bool> &instack){
        if(instack[node])
            return 1;
        if(vis[node])
            return 0;
        vis[node]=instack[node]=1;
        for(auto v:adj[node])
            if(cyclic(v,vis,instack))
                return 1;
        return instack[node]=0;
    }
};