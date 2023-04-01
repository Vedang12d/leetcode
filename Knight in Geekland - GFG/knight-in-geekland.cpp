//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define pi pair<int,int>
#define ff first
#define ss second

class Solution{
public:
    int knightInGeekland(int x,int y,vector<vector<int>> &v){
        int m=v.size(),n=v[0].size();
        vector<pi> dir={{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};
        vector<vector<bool>> vis(m,vector<bool>(n));
        vis[x][y]=1;
        queue<pi> q;
        q.push({x,y});
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            ans.push_back(0);
            while(size--){
                int r=q.front().ff,c=q.front().ss;
                q.pop();
                ans.back()+=v[r][c];
                for(auto &d:dir){
                    int nr=r+d.ff,nc=c+d.ss;
                    if(nr<0||nc<0||nr>=m||nc>=n||vis[nr][nc])
                        continue;
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            for(int step=i;step<ans.size()&&ans[step];){
                step+=ans[step];
                if(step<ans.size())
                    ans[i]+=ans[step];
            }
        }
        return max_element(ans.begin(),ans.end())-ans.begin();
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends