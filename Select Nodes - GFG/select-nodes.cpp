//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    void dfs(vector<vector<int>> &adj,int node,int parent,vector<array<int,2>> &dp){
        for(auto &child:adj[node])
            if(child!=parent)
                dfs(adj,child,node,dp);
        for(auto &child:adj[node]){
            if(child!=parent){
                dp[node][0]+=dp[child][1];
                dp[node][1]+=min(dp[child][0],dp[child][1]);
            }
        }
    }
    int countVertex(int n, vector<vector<int>>edges){
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[--e[0]].push_back(--e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<array<int,2>> dp(n,{0,1});
        dfs(adj,0,0,dp);
        return min(dp[0][0],dp[0][1]);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends