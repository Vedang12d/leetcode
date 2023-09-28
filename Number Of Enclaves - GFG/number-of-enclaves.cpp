//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<array<int,2>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>> &grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or !grid[i][j])
            return;
        grid[i][j]=0;
        for(auto &d:dir){
            int ni=i+d[0],nj=j+d[1];
            dfs(grid,ni,nj);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i or !j or i==n-1 or j==m-1)
                    dfs(grid,i,j);
            }
        }
        for(auto &i:grid){
            for(auto &j:i){
                if(j)
                    ans++;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends