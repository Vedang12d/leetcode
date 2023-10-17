//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> vis;
    bool isSafe(int u,vector<int> adj[]){
        if(vis[u]!=-1)
            return vis[u];
        if(adj[u].empty())
            return vis[u]=true;
        vis[u]=0;
        for(auto &v:adj[u]){
            if(!isSafe(v,adj))
                return vis[u]=false;
        }
        return vis[u]=true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vis.resize(V,-1);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(isSafe(i,adj))
                ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends