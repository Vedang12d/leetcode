//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
    void dfs(int i,int j,vector<vector<int>>& matrix, int &N, int &M){
        if(i<0||j<0||i>=N||j>=M||!matrix[i][j])
            return;
        matrix[i][j]=0;
        for(auto &d:dir)
            dfs(i+d[0],j+d[1],matrix,N,M);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if((!i||!j||i==N-1||j==M-1) and matrix[i][j])
                    dfs(i,j,matrix,N,M);
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(matrix[i][j]){
                    dfs(i,j,matrix,N,M);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends