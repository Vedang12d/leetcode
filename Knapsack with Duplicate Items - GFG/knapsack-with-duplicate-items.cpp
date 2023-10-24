//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int solve(int i, int w, int val[], int wt[]){
        if(i<0)
            return 0;
        if(dp[i][w]!=-1)
            return dp[i][w];
        int pick=0;
        if(w>=wt[i])
            pick=val[i]+solve(i,w-wt[i],val,wt);
        int notpick=solve(i-1,w,val,wt);
        return dp[i][w]=max(pick,notpick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        dp.resize(N+1,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends