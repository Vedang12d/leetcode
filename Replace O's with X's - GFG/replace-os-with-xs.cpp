//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<array<int,2>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<char>> &mat){
        if(i<0 or j<0 or i>=mat.size() or j>=mat[0].size() or mat[i][j]!='O')
            return;
        mat[i][j]='$';
        for(auto &d:dir)
            dfs(i+d[0],j+d[1],mat);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O')
                dfs(i,0,mat);
            if(mat[i][m-1]=='O')
                dfs(i,m-1,mat);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O')
                dfs(0,i,mat);
            if(mat[n-1][i]=='O')
                dfs(n-1,i,mat);
        }
        for(auto &i:mat){
            for(auto &j:i){
                if(j=='O')
                    j='X';
                else if(j=='$')
                    j='O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends