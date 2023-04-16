//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int N;
    vector<vector<int>> dp;
    int bt(int i,int W,int val[],int wt[]){
        if(i==N||!W)
            return 0;
        if(dp[i][W]!=-1)
            return dp[i][W];
        int a=bt(i+1,W,val,wt);
        if(wt[i]<=W)
            a=max(a,val[i]+bt(i,W-wt[i],val,wt));
        return dp[i][W]=a;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        this->N=N;
        dp.resize(N+1,vector<int>(W+1,-1));
        return bt(0,W,val,wt);
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