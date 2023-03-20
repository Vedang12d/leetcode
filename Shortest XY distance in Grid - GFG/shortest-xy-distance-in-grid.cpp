//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        int ans=0;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(N,vector<bool>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]=='X'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<array<int,2>> dir={{1,0},{0,-1},{-1,0},{0,1}};
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto t=q.front();
                q.pop();
                for(auto &d:dir){
                    int ni=t.first+d[0],nj=t.second+d[1];
                    if(ni>=0&&ni<N&&nj>=0&&nj<M&&!vis[ni][nj]){
                        if(grid[ni][nj]=='Y')
                            return ans+1;
                        vis[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends