//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> ans(N,-1);
        vector<vector<pair<int,int>>> adj(N);
        for(auto &e:edges)
            adj[e[0]].push_back({e[1],e[2]});
        queue<pair<int,int>> q;
        q.push({0,0});
        ans[0]=0;
        while(!q.empty()){
            int u=q.front().first,d=q.front().second;
            q.pop();
            for(auto &x:adj[u]){
                int v=x.first,nd=d+x.second;
                if(ans[v]==-1 or ans[v]>nd)
                    ans[v]=nd, q.push({v,nd});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends