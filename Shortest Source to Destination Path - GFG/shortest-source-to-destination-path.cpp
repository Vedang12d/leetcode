//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(!A[0][0])
            return -1;
        vector<pair<int,int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({0,0});
        A[0][0]=0;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front().first,j=q.front().second;
                if(i==X and j==Y)
                    return ans;
                q.pop();
                for(auto &d:dir){
                    int ni=i+d.first, nj=j+d.second;
                    if(ni<0 or nj<0 or ni>=N or nj>=M or !A[ni][nj])
                        continue;
                    A[ni][nj]=0;
                    q.push({ni,nj});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends