//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>> dist(n,vector<int>(m));
        vector<vector<bool>> vis(n,vector<bool>(m));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        vector<array<int,2>> dirs={{0,-1},{-1,0},{1,0},{0,1}};
        int dis=0;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                int row=q.front().first, col=q.front().second;
                q.pop();
                for(auto &dir:dirs){
                    int nr=row+dir[0], nc=col+dir[1];
                    if(nr>=0 and nc>=0 and nr<n and nc<m and c[nr][nc]!='N' and !vis[nr][nc]){
                        dist[nr][nc]=dis+2;
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            dis+=2;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='.')
                    dist[i][j]=0;
                else if(c[i][j]=='H' and !vis[i][j])
                    dist[i][j]=-1;
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends